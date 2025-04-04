/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 11:35:17 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/25 00:21:46 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

static int	check_mult_here_doc(t_token *tokens)
{
	int		counter;
	t_token	*tmp;

	counter = 0;
	tmp = tokens;
	while (tmp)
	{
		if (tmp->type == HERE_DOC)
			counter++;
		tmp = tmp->next;
	}
	return (counter);
}

static void	mult_here_doc_error(t_shell *shell, t_token *tokens)
{
	t_token	*tmp;

	tmp = tokens;
	while (tmp)
	{
		if (tmp->type == HERE_DOC && tmp->next)
		{
			if (tmp->next->type == HERE_DOC)
			{
				ft_dprintf(2,
					"42shell: syntax error near unexpected token '%s'\n",
					tmp->value);
				shell->exit_status = 2;
				unlink(".DOC_TMP");
				return ;
			}
		}
		tmp = tmp->next;
	}
	ft_dprintf(2,
		"42shell: This version do not fuck with multiples '<<'\n");
	shell->exit_status = 2;
	unlink(".DOC_TMP");
}

static void	init_pipe(t_pipe *pipe, t_token *tokens, t_shell *shell)
{
	if (!pipe)
		error_message("malloc");
	pipe->i = 0;
	pipe->input_fd = 0;
	pipe->flag = pipe_flag(tokens, shell);
}

void	executer(t_shell *shell, t_token *tokens)
{
	t_pipe	*pipes;
	t_token	*cmd_start;

	if (check_mult_here_doc(tokens) > 1)
	{
		mult_here_doc_error(shell, tokens);
		return ;
	}
	pipes = malloc(sizeof(t_pipe));
	init_pipe(pipes, tokens, shell);
	cmd_start = tokens;
	while (cmd_start && (pipes->flag == 1 || pipes->flag == 0))
	{
		if ((cmd_start->type == PIPE || !cmd_start->next) && pipes->flag == 1)
		{
			pipe_executer(shell, tokens, pipes, cmd_start->type);
			tokens = cmd_start->next;
		}
		else if (!cmd_start->next && !pipes->flag)
			command_executer(shell, tokens);
		cmd_start = cmd_start->next;
	}
	if (here_doc_flag(tokens))
		unlink(".DOC_TMP");
	free(pipes);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_executer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 16:47:12 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/24 22:06:31 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

void	execute_command(t_token *token, t_shell *shell)
{
	char	*path;
	char	**args;
	char	**env;

	if (!token)
		return ;
	args = tokenize_command(token);
	env = env_to_matrix(shell->env);
	execute_full_command(args, env, STDIN_FILENO, STDOUT_FILENO);
	path = path_verifier(args, env);
	if (!path)
	{
		ft_dprintf(2, "42shell: %s: command not found\n", args[0]);
		shell->exit_status = 127;
		free_matrix(env);
		ft_free(&path);
		free_matrix(args);
		exit(shell->exit_status);
	}
	if (execve(path, args, env) == -1)
		error_message("execve");
}

void	redirect_builtins(t_shell *shell, t_token *tokens)
{
	pid_t	id;

	id = fork();
	if (id == -1)
		error_message("fork");
	if (id == 0)
	{
		execute_redirections(tokens, shell);
		execute_builtins(shell, tokens);
		exit(shell->exit_status);
	}
	waitpid(id, &shell->exit_status, 0);
	shell->exit_status = exit_status_signal(shell->exit_status);
}

int	redirection_flag(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (is_redirection(tmp->type))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	command_executer(t_shell *shell, t_token *tokens)
{
	pid_t	id;

	if (is_builtin(tokens->type))
	{
		if (redirection_flag(tokens))
			redirect_builtins(shell, tokens);
		else
			execute_builtins(shell, tokens);
	}
	else
	{
		id = fork();
		if (id == -1)
			error_message("fork");
		if (id == 0)
		{
			signal(SIGINT, SIG_DFL);
			execute_redirections(tokens, shell);
			execute_command(tokens, shell);
		}
		signal(SIGINT, process_signal_handler);
		waitpid(id, &shell->exit_status, 0);
		shell->exit_status = exit_status_signal(shell->exit_status);
	}
}

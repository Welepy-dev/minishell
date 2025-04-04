/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:49:03 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/23 16:02:01 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

static void	free_env(t_env *head)
{
	t_env	*tmp;

	while (head)
	{
		tmp = head->next;
		ft_free(&head->name);
		ft_free(&head->value);
		if (head)
		{
			free(head);
			head = NULL;
		}
		head = tmp;
	}
}

void	clean_or_exit(t_shell *shell)
{
	free_env(shell->env);
	ft_free(&shell->input);
	free_tokens(shell->token);
	free_matrix(shell->array);
	ft_free(&shell->path);
	rl_clear_history();
}

static int	modulo(long long int exit_status)
{
	if (exit_status >= 0 && exit_status <= 255)
		return (exit_status);
	return (exit_status % 256);
}

int	ft_exit(t_shell *shell, t_token *token)
{
	char	*str;

	if (token->next)
	{
		str = ft_strtrim(token->next->value, " \n\t");
		errno = 0;
		if (str)
			shell->exit_status = modulo(ft_atol(str));
		printf("exit\n");
		if (ft_atol(str) == 939552403)
		{
			shell->exit_status = 2;
			ft_dprintf(2, "exit: %s: numeric argument required\n", (str));
		}
		else if (token->next->next)
		{
			shell->exit_status = 1;
			ft_free(&str);
			return (ft_dprintf(2, "exit: too many arguments\n"));
		}
		ft_free(&str);
	}
	clean_or_exit(shell);
	exit(shell->exit_status);
}

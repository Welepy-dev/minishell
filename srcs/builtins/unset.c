/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:49:17 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/22 18:53:23 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

void	remove_env(t_env **env, char *name)
{
	t_env	*current;
	t_env	*prev;
	char	**tok;

	prev = NULL;
	current = *env;
	tok = ft_split(name, '=');
	while (current)
	{
		if (!ft_strcmp(current->name, tok[0]))
		{
			if (prev)
				prev->next = current->next;
			else
				*env = current->next;
			free(current->name);
			free(current->value);
			free(current);
			free_matrix(tok);
			return ;
		}
		prev = current;
		current = current->next;
	}
	free_matrix(tok);
}

void	ft_unset(t_env *env, t_token *token, t_shell *shell, bool flag)
{
	t_token	*temp;

	temp = token;
	if (!flag)
		temp = token->next;
	if (token->next && token->next->type == OPTION)
	{
		shell->exit_status = 1;
		ft_dprintf(2, "unset: this version doesn't support options");
		return ;
	}
	while (temp && temp->type == ARGUMENT)
	{
		remove_env(&env, temp->value);
		temp = temp->next;
	}
	shell->exit_status = 0;
}

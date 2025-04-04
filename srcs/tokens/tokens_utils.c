/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 12:15:54 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/24 17:01:00 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

static void	is_command_util(char **paths, int *tab, char *value)
{
	char	*tmp;

	tmp = ft_strjoin(paths[tab[0]], "/");
	free(paths[tab[0]]);
	paths[tab[0]] = ft_strjoin(tmp, value);
	free(tmp);
}

bool	is_command(char *value, char *path)
{
	char	**paths;
	int		tab[2];

	tab[1] = 0;
	tab[0] = 0;
	paths = ft_split(path, ':');
	while (paths[tab[0]])
	{
		is_command_util(paths, tab, value);
		tab[0]++;
	}
	tab[0] = 0;
	while (paths[tab[0]])
	{
		if (access(paths[tab[0]], F_OK) == 0)
		{
			tab[1] = 1;
			break ;
		}
		tab[0]++;
	}
	free_matrix(paths);
	return (tab[1]);
}

t_token	*new_token(char *value, t_type type)
{
	t_token	*new_token;

	new_token = safe_malloc(sizeof(t_token));
	new_token->value = ft_strdup(value);
	new_token->type = type;
	new_token->next = NULL;
	return (new_token);
}

void	token_sequence(t_token *tokens)
{
	int		found_command;
	t_token	*head;

	found_command = 0;
	head = tokens;
	while (head)
	{
		if (is_redirection(head->type) || head->type == PIPE)
			break ;
		if (is_builtin_or_command(head->type))
		{
			if (found_command)
				head->type = ARGUMENT;
			else
				found_command = 1;
		}
		head = head->next;
	}
}

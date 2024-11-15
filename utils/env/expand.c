/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:37:07 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/15 15:42:46 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static char	*get_env_value(t_env *env, char *name)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, name))
			return (tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}

void	expand(char ***matrix, t_env *env)
{
	int		y;
	char	*value;

	y = 0;
	while ((*matrix)[y])
	{
		if ((*matrix)[y][0] == '$')
		{
			value = get_env_value(env, &(*matrix)[y][1]);
			free((*matrix)[y]);
			if (value)
				(*matrix)[y] = ft_strdup(value);
			else
				(*matrix)[y] = ft_strdup("");
		}
		y++;
	}
}

//verify if every var exist in env if not return NULL
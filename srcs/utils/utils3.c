/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:20:16 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/18 22:29:04 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

int	here_doc_flag(t_token *token)
{
	t_token	*tmp;

	tmp = token;
	while (tmp)
	{
		if (tmp->type == HERE_DOC)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_env	*convert_env(char **env)
{
	t_env	*list;
	t_env	*new;
	int		i;

	list = NULL;
	i = 0;
	while (env[i])
	{
		new = malloc(sizeof(t_env));
		if (!new)
		{
			ft_lstclear((t_list **)&list, free);
			return (NULL);
		}
		new->name = ft_strndup(env[i], ft_strcspn(env[i], "="));
		new->value = ft_strdup(env[i] + ft_strcspn(env[i], "=") + 1);
		new->next = NULL;
		ft_lstadd_back((t_list **)&list, (t_list *)new);
		i++;
	}
	return (list);
}

char	*get_path(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, "PATH") == 0)
			return (ft_strdup(tmp->value));
		tmp = tmp->next;
	}
	return (NULL);
}

void	empty_input(t_shell *shell)
{
	ft_putstr_fd("exit\n", 2);
	ft_free(&shell->path);
	exit(shell->exit_status);
}

char	*get_env_value(char *name, t_env *env)
{
	while (env)
	{
		if (ft_strcmp(env->name, name) == 0)
			return (env->value);
		env = env->next;
	}
	return (NULL);
}

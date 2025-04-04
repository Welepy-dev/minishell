/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 21:08:38 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/24 17:15:07 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

static bool	check_path(char *str, char ***paths)
{
	if (access(str, F_OK) == 0)
	{
		free_matrix(*paths);
		return (true);
	}
	return (false);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	*matrix[2];
	char	**paths;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		matrix[1] = ft_strjoin(paths[i], "/");
		matrix[0] = ft_strjoin(matrix[1], cmd);
		ft_free(&matrix[1]);
		if (check_path(matrix[0], &paths))
			return (matrix[0]);
		ft_free(&matrix[0]);
	}
	free_matrix(paths);
	return (NULL);
}

char	**env_to_matrix(t_env *env)
{
	t_env	*tmp;
	char	**matrix;
	int		i;
	char	*temp;

	tmp = env;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	matrix = safe_malloc(sizeof(char *) * (i + 1));
	tmp = env;
	i = -1;
	while (tmp)
	{
		matrix[++i] = ft_strjoin(tmp->name, "=");
		temp = ft_strjoin(matrix[i], tmp->value);
		ft_free(&matrix[i]);
		matrix[i] = temp;
		tmp = tmp->next;
	}
	matrix[++i] = NULL;
	return (matrix);
}

char	*remove_quotes(const char *str)
{
	size_t	len;
	size_t	new_len;
	char	*new_str;

	len = ft_strlen(str);
	if (len >= 2 && ((str[0] == '"' && str[len - 1] == '"')
			|| (str[0] == '\'' && str[len - 1] == '\'')))
	{
		new_len = len - 2;
		new_str = safe_malloc(new_len + 1);
		ft_strncpy(new_str, str + 1, new_len);
		new_str[new_len] = '\0';
		return (new_str);
	}
	return (ft_strdup(str));
}

void	free_tokens(t_token *head)
{
	t_token	*tmp;

	while (head)
	{
		tmp = head->next;
		ft_free(&head->value);
		if (head)
		{
			free(head);
			head = NULL;
		}
		head = tmp;
	}
}

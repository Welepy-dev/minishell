/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:46:17 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/24 18:14:51 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

static bool	permission_check(t_shell *shell, char *path)
{
	if (access(path, F_OK) != 0)
	{
		ft_dprintf(2, "42shell: cd: %s: No such file or directory\n", path);
		shell->exit_status = 1;
		return (false);
	}
	if (access(path, X_OK) != 0)
	{
		ft_dprintf(2, "42shell: cd: %s: Permission denied\n", path);
		shell->exit_status = 1;
		return (false);
	}
	return (true);
}

static void	ft_cd_prev(char	*prev_path, t_shell *shell)
{
	if (!prev_path)
	{
		ft_dprintf(2, "cd: OLDPWD not set\n");
		shell->exit_status = 1;
		return ;
	}
	else
	{
		if (!permission_check(shell, prev_path))
			return ;
		if (chdir(prev_path) == 0)
		{
			printf("%s\n", prev_path);
			shell->exit_status = 0;
		}
	}
}

static void	ft_cd_aux(t_token *current, char *cur_path, t_shell *shell)
{
	char	*path;
	char	*new_path;

	shell->exit_status = 0;
	path = ft_strjoin(cur_path, "/");
	new_path = ft_strjoin(path, current->value);
	ft_free(&path);
	if (*current->value == '~')
	{
		ft_free(&new_path);
		new_path = ft_strjoin(getenv("HOME"), current->value + 1);
	}
	if (!permission_check(shell, new_path))
	{
		ft_free(&new_path);
		ft_free(&cur_path);
		return ;
	}
	if (chdir(new_path) == -1)
	{
		ft_dprintf(2, "cd: %s", current->value);
		shell->exit_status = 1;
	}
	ft_free(&new_path);
	ft_free(&cur_path);
}

static int	cd_error(char *cur_path, int flag, t_shell *shell, t_token *token)
{
	if (token->next && flag == 0)
	{
		ft_putstr_fd("42shell: cd: too many arguments\n", 2);
		shell->exit_status = 1;
		ft_free(&cur_path);
		return (true);
	}
	if (token->next && token->next->type == OPTION && flag == 1)
	{
		ft_dprintf(2, "42shell: cd: this version doesn't allow options\n");
		shell->exit_status = 1;
		return (true);
	}
	return (false);
}

void	ft_cd(t_token *current, t_shell *shell)
{
	char		*cur_path;
	static char	*prev_path;
	t_token		*token;

	if (cd_error(NULL, 1, shell, current))
		return ;
	token = current->next;
	if (!token)
	{
		chdir(getenv("HOME"));
		return ;
	}
	cur_path = getcwd(NULL, 0);
	if (cd_error(cur_path, 0, shell, token))
		return ;
	if (ft_strcmp(token->value, "-") == 0)
	{
		ft_cd_prev(prev_path, shell);
		ft_free(&prev_path);
		prev_path = ft_strdup(cur_path);
		return ;
	}
	ft_cd_aux(token, cur_path, shell);
}

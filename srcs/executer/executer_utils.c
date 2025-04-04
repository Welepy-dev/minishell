/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:20:55 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/24 23:55:17 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

void	execute_builtins(t_shell *shell, t_token *token)
{
	if (ft_strcmp(token->value, "echo") == 0)
		ft_echo(token, shell);
	else if (ft_strcmp(token->value, "cd") == 0)
		ft_cd(token, shell);
	else if (ft_strcmp(token->value, "pwd") == 0)
		ft_pwd(token, shell);
	else if (ft_strcmp(token->value, "env") == 0)
		ft_env(shell->env, token, shell, false);
	else if (ft_strcmp(token->value, "export") == 0)
		ft_export(shell->env, token, shell);
	else if (ft_strcmp(token->value, "unset") == 0)
		ft_unset(shell->env, token, shell, false);
	else if (ft_strcmp(token->value, "exit") == 0)
		ft_exit(shell, token);
}

void	execute_full_command(char **args, char **env, int in, int out)
{
	char	*path;

	if (((ft_strncmp("./", args[0], 2) == 0 || (args[0][0] == '/')) \
		&& access(args[0], F_OK) == 0))
	{
		path = ft_strdup(args[0]);
		args[0] = ft_strtrim(args[0], "/bin/");
		if (in != 0)
			ft_dup3(in, STDIN_FILENO);
		if (out != 1)
			ft_dup3(out, STDOUT_FILENO);
		if (execve(path, args, env) == -1)
			error_message("execve");
	}
}

char	*path_verifier(char **args, char **env)
{
	if (!args[0][0])
		return (NULL);
	return (find_path(args[0], env));
}

void	clean_t_pipe(t_pipe *pipes, char *str)
{
	free(pipes);
	error_message(str);
}

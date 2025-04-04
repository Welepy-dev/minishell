/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:16:24 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/02 13:38:58 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minihell.h"

volatile sig_atomic_t	g_sigint;
char	*token_kind_string(t_type type)
{
	if (type == GREATER)
		return ("GREATER");
	else if (type == LESSER)
		return ("LESSER");
	else if (type == APPEND)
		return ("APPEND");
	else if (type == HERE_DOC)
		return ("Here-doc");
	else if (type == PIPE)
		return ("PIPE");
	else if (type == COMMAND)
		return ("COMMAND");
	else if (type == ARGUMENT)
		return ("ARGUMENT");
	else if (type == SINGLE_QUOTE)
		return ("SINGLE_QUOTE");
	else if (type == DOUBLE_QUOTE)
		return ("DOUBLE QUOTE");
	else if (type == BUILTINS)
		return ("Builtins");
	else if (type == OPTION)
		return ("OPTION");
	else if (type == FULL_COMMAND)
		return ("FULL_COMMAND");
	else if (type == IDENTIFIER)
		return ("IDENTIFIER");
	else
		return ("UNKNOWN");
}

void	debug(t_token *token)
{
	t_token	*head;

	head = token;
	while (head)
	{
		printf("%s, type: %s\n", head->value, token_kind_string(head->type));
		head = head->next;
	}
	printf("\n");
}

static bool	read_input(t_shell *shell)
{
	char	*raw_input;
	char	*pwd;
	char	*user;

	user = getenv("USER");
	if (!user)
		user = ft_strdup("");
	pwd = safe_malloc(PATH_MAX);
	getcwd(pwd, PATH_MAX);
	printf("┌[%s] - [%s]\n", user, pwd);
	raw_input = readline("└─[$] ");
	if (!raw_input)
		empty_input(shell);
	if (*raw_input)
		add_history(raw_input);
	if (all_spaces(raw_input))
	{
		ft_free(&raw_input);
		ft_free(&pwd);
		return (false);
	}
	shell->input = ft_strtrim(raw_input, " \t\n");
	ft_free(&raw_input);
	ft_free(&pwd);
	return (true);
}

void	init_shell(t_shell *shell, char **env)
{
	shell->input = NULL;
	shell->exit_status = 0;
	shell->array = NULL;
	shell->flag = true;
	shell->env = convert_env(env);
	shell->path = get_path(shell->env);
	shell->token = NULL;
	shell->pipe = NULL;
}

void	repl(t_shell *shell)
{
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		set_sigint(&shell->exit_status, 0);
		signal(SIGINT, signal_handler);
		if (!read_input(shell))
			continue ;
		parse(shell);
		// debug(shell->token);
		if (shell->flag)
		{
			executer(shell, shell->token);
			free_tokens(shell->token);
			free_matrix(shell->array);
		}
		ft_free(&shell->input);
	}
}

int	main(int ac, char **av, char **env)
{
	t_shell	*shell;

	if (ac == 1)
	{
		shell = malloc(sizeof(t_shell));
		init_shell(shell, env);
		repl(shell);
	}
	else
		ft_dprintf(2, "%s do not receive argument!\n", av[0]);
	return (0);
}

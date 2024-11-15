/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:22:46 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/15 13:12:33 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

int	main(int ac, char **av, char **environment)
{
	t_shell	shell;

	shell.env = NULL;


	if (ac != 1)
		print_error("Error: too many arguments", NULL);
	shell.env = convert_env(environment);
	while (1)
	{
		shell.input = readline("minishell$ ");
		if (!shell.input)
			break ;
		add_history(shell.input);
		shell.matrix = split_input(shell.input);
		if (!shell.input)
		{
			fprintf(stderr, "Failed to parse input");
			continue ;
		}
		expand(&shell.matrix, shell.env);
		int	y = 0;
		while (shell.matrix[y])
			printf("%s\n", shell.matrix[y++]);
	}
	// char **split = ft_split(environment[0], '=');
	// printf("%s\n", split[0]);
	// printf("%s\n", split[1]);
	// char	*str = ft_strdup(env[0]);
	// int	y = 0;
	// while (env[y])
	// 	printf("%s\n", env[y++]);
	// shell.env = convert_env(environment);
	// printf("name: %s\n", shell.env->name);
	// printf("value: %s\n", shell.env->value);

	// while (shell.env)
	// {
	// 	shell.env = shell.env->next;
	// }
	// while (1)
	// {
	// 	shell.input = readline("minishell$ ");
	// 	if (!shell.input)
	// 		break ;
	// 	add_history(shell.input);
	// 	shell.matrix = split_input(shell.input);
	// 	int	y = 0;
	// 	while (shell.matrix[y])
	// 	{
	// 		printf("matrix[%d]: %s\n", y, shell.matrix[y]);
	// 		y++;
	// 	}
	// 	if (!shell.matrix)
	// 		continue ;
	// }
	// clean_and_exit(&shell);
	(void)av;
	return (0);
}

/*
//initialize shell
	//read the input
		// //parse the input
		// 	//tokenize the input
		// 	//parse the tokens
			//execute the command
	//repeat
		TODO
	at the end of else chain if it finds a bad char or wrong char e.g. when
	 extracts a opeartor but still finds a operator
search what are valid token orders
  search how to tokenize a string
  search how to parse a string
  search how to execute a command
  search how to read a line
  search expansion
when ctrl + D is pressed, exit the program
when ctrl + C is send a signal to cancel the current command
when ctrl + \ is pressed, do nothing
looks first for commands or redirections
if the first token is a '*' will have the default behaviour of the shell
if is a'$' first expands it and sees if is a command if not, writes command not
found
if is a ctrl command does the work accordingly
struct named tokens: will have command arguments and operators
to tokenize:
skip unnecessary whitespace
first split
then expand if there is
then tokenise
	SHOULD PRINT PARSE ERROR WHEN FINDING SEQUENCE OF OPERATORS

	t_env	*convert_env(char **env)
{
	t_env	*list;
	t_env	*new;
	int		i;
	char	**split;

	list = NULL;
	i = 0;
	while (env[i])
	{
		split = ft_split(env[i], '=');
		if (!split)
		{
			ft_lstclear((t_list **)&list, free);
			return (NULL);
		}
		new = malloc(sizeof(t_env));
		if (!new)
		{
			ft_lstclear((t_list **)&list, free);
			return (NULL);
		}
		new->name = ft_strdup(split[0]);
		new->value = ft_strdup(split[1]);
		new->next = NULL;
		ft_lstadd_back((t_list **)&list, (t_list *)new);
		free_matrix(split);
		i++;
	}
	return (list);
}
*/
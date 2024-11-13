/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:22:46 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/13 16:10:14 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minishell.h"

static char	*extract_quote(char **input)
{
	char	*quote;
	int		i;

	i = 0;
	(*input)++;							//ignorar o primeiro character "\"" ou "\'"
	while ((**input != '\'' || **input != '\"') && (**input))	//saber o tabanho da string dentro de ("")  exemplo: ".....$USER...." i = 14
	{
		(*input)++;
		i++;
	}
	quote = ft_strndup((*input) - i, (i - 1));
	if (**input)
		(*input)++;						//se for != de null avança para a proxima casa, desse jeito ignora as ulimas aspas
	printf("quote: %s\n", quote);
	return (quote);
}

static char	*extract_operator(char **input)
{
	char	*operator;
	char	temp_char;
	int		i;
	int		operator_size;

	temp_char = **input;
	operator_size = 0;
	i = 0;
	if (!ft_strbspn(*input, temp_char))
		print_error("Parse error", NULL);
	while ((**input == temp_char) && (operator_size < 2))
	{
		++operator_size;
		(*input)++;
	}
	operator = safe_malloc(sizeof(char) * (operator_size + 1));
	while (i < operator_size)
	{
		operator[i++] = temp_char;
		(*input)++;
	}
	operator[i] = '\0';
	printf("operator %s\n", operator);
	return (operator);
}


//tem de se fazer ajustes para que se contar ".......$USER...." como uma unica string
static int	word_count(char *input)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (input[i])
	{
		if (ft_isspace(input[i]))
			i++;
		else
		{
			count++;
			while (input[i] && !ft_isspace(input[i]))
				i++;
		}
	}
	return (count);
}

char	*extract_command(char **input)
{
	char	*command;
	int	i;

	i = 0;
	while (**input && !ft_isspace(**input))
	{
		i++;
		(*input)++;
	}
	command = ft_strndup((*input) - i, i);
	printf("command: %s\n", command);
	return (command);
}

char	**split_input(char *input)
{
	char	**matrix;
	int		y;

	y = 0;
	if (!input)
		return (NULL);
	matrix = safe_malloc(sizeof(char *) * (word_count(input) + 1));
	printf("word count: %d\n", word_count(input));
	while (*input)
	{
		while ((ft_isspace(*input)) && *input)
			input++;
		if (*input == '\'' || *input == '\"')
			matrix[y++] = extract_quote(&input);
		else if (contains_char(input, "|<>&*"))
			matrix[y++] = extract_operator(&input);
		else if (ft_isalnum(*input))
			matrix[y++] = extract_command(&input);
		/*else
		{
			ft_putstr_fd("Parse error at: ", 2);
			ft_putchar_fd(*input, 2);
			ft_putchar_fd('\n', 2);
		}*/
	}
	matrix[y] = NULL;
	if (matrix == NULL)
		print_error("Parse error", NULL);
	return (matrix);
}

int	main(int ac, char **av, char **env)
{
	t_shell	shell;

	(void)av;
	(void)env;
	if (ac != 1)
		print_error("Error: too many arguments", NULL);
	//initialize shell
	//read the input
	while (1)
	{
		shell.input = readline("minishell$ ");
		if (!shell.input)
			break ;
		shell.matrix = split_input(shell.input);
		if (!shell.matrix)
			continue ;
		printf("input: %s\n", shell.input);
		printf("matrix:\n");
		int	y = 0;
		while (shell.matrix[y])
			printf("%s\n", shell.matrix[y++]);
		// //parse the input
		// 	//tokenize the input
		// 	//parse the tokens
	}
	clean_and_exit(&shell);
	//execute the command
	//repeat
	return (0);
}

/*search what are valid token orders
  search how to tokenize a string
  search how to parse a string
  search how to execute a command
  search how to read a line
  search expansion
when ctrl + D is pressed, exit the program
when ctrl + C is send a signal to cancel the current command
when ctrl + \ is pressed, do nothing
*/

/*looks first for commands or redirections*/
/*if the first token is a '*' will have the default behaviour of the shell
if is a'$' first expands it and sees if is a command if not, writes command not found*/
/*if is a ctrl command does the work accordingly*/

/*struct named tokens: will have command arguments and operators*/
/*to tokenize:
skip unnecessary whitespace*/

/*first split
then expand if there is
then tokenise*/

/*
	SHOULD PRINT PARSE ERROR WHEN FINDING SEQUENCE OF OPERATORS
*/
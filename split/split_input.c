/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:55:56 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/15 12:38:48 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	word_count(char *input)
{
	int	count;

	count = 0;
	count = word_count_util(input, count);
	return (count);
}

static char	*extract_command(char **input)
{
	char	*command;
	int		i;

	i = 0;
	while (**input && !ft_isspace(**input) && \
	!ft_strchr("|<>&*\"\'", **input))
	{
		i++;
		(*input)++;
	}
	command = ft_strndup((*input) - i, i);
	// printf("command: %s\n", command);
	return (command);
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
	while ((**input == temp_char) && (operator_size < 2))
	{
		++operator_size;
		(*input)++;
	}
	if (!extract_operator_util(input))
		return (NULL);
	operator = safe_malloc(sizeof(char) * (operator_size + 1));
	while (i < operator_size)
		operator[i++] = temp_char;
	operator[i] = '\0';
	// printf("operator: %s\n", operator);
	return (ft_string_split(operator, ' '));
}

static char	*extract_quote(char **input)
{
	int		i;
	char	quote;
	char	*quote_string;

	i = 0;
	quote = **input;
	(*input)++;
	while (**input)
	{
		if (**input == quote)
		{
			if (*(*input + 1) == quote)
				(*input)++;
			else
				break ;
		}
		(*input)++;
		i++;
	}
	quote_string = fill_quote(input, quote, i);
	if (**input)
		(*input)++;
	// printf("quote_string: %s\n", quote_string);
	return (quote_string);
}

char	**split_input(char *input)
{
	char	**matrix;
	int		y;

	y = 0;
	if (!input)
		return (NULL);
	matrix = safe_malloc(sizeof(char *) * (word_count(input) + 1));
	if (!validate_quote_number(input))
		printf("Error: can't parse unclosed quotes\n");			//use fprintf
	// printf("word count: %d\n", word_count(input));
	while (*input)
	{
		while ((ft_isspace(*input)) && *input)
			input++;
		if (*input == '\'' || *input == '\"')
			matrix[y++] = extract_quote(&input);
		else if (ft_strchr("|<>*&", *input))
			matrix[y++] = extract_operator(&input);
		else if (ft_isalnum(*input) || *input == '_' || *input == '/' \
		|| *input == '.' || *input == '-' || *input == '~')
			matrix[y++] = extract_command(&input);
		else if (*input == '$')
			matrix[y++] = extract_variable(&input);
		else
			printf("Error: invalid character %c\n", *input++);	//use fprintf
	}
	matrix[y] = NULL;
	if (matrix == NULL)
		return (NULL);
	return (matrix);
}

/*static char	*extract_quote(char **input)
{
	int		i = 0;
	char	quote = **input;
	char	*quote_string;

	(*input)++;
	while (**input)
	{
		if (**input == quote && *(*input + 1) != quote)
			break;
		else if (**input == quote)
			(*input)++;
		(*input)++;
		i++;
	}
	quote_string = fill_quote(input, quote, i);
	if (**input)
		(*input)++;
	printf("quote_string: %s\n", quote_string);
	return (quote_string);
}*/
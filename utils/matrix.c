/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:11:11 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/13 15:19:31 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*static char	*extract_quote(char **input)
{
	char	*quote;
	int		i;

	i = 0;
	++input;
	while ((*input != '\'' || *input != '\"') && (*input))
	{
		input++;
		i++;
	}
	quote = ft_strndup(input, i);
	printf("quote: %s", quote);
	return (quote);
}

static char	*extract_operator(char **input)
{
	char	*operator;
	char	temp_char;
	int		i;
	int		operator_size;

	temp_char = *input;
	operator_size = 0;
	i = 0;
	while ((*input == temp_char) && (operator_size < 2))
	{
		++operator_size;
		++input;
	}
	operator = safe_malloc(sizeof(char) * (operator_size + 1));
	while (i < operator_size)
	{
		operator[i++] = temp_char;
		++input;
	}
	operator[i] = '\0';
	printf("operator %s\n", operator);
	return (operator);
}

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
	while (*input && !ft_isspace(*input))
	{
		i++;
		input++;
	}
	command = ft_strndup(input, i);
	printf("command: %s", command);
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
	printf("word count: %d\n", word_count);
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
		else
		{
			ft_putstr_fd("Parse error at: ", 2);
			ft_putchar_fd(*input, 2);
			ft_putchar_fd('\n', 2);
		}
	}
	if (matrix == NULL)
		print_error("Parse error", NULL);
	return (matrix);
}*/
/*
	skip initial spaces
	allocate memory for the matrix
	allocate memory for each row
	use strndup to copy the string
*/

/*
char **split_input(const char *input) {
    char **result = NULL;
    size_t count = 0;

    while (*input) {
        if (is_space(*input)) {
            skip_spaces(&input);
        } else if (is_quote(*input)) {
            char *quoted = extract_quoted(&input);
            add_to_result(&result, &count, quoted);
        } else if (is_operator(*input)) {
            char *operator = extract_operator(&input);
            add_to_result(&result, &count, operator);
        } else {
            char *word = extract_word(&input);
            add_to_result(&result, &count, word);
        }
    }
    return result;
}
*/

//use and idenx to go through the string then use pointer arithmetic to increment the string pos
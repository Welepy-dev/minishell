/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 02:56:56 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/02 16:26:29 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

static char	*take_quote(char **input)
{
	char	*current;
	size_t	total_len;
	char	*result;

	current = *input;
	total_len = calculate_unquoted_length(&current);
	if (total_len == 0)
		return (NULL);
	result = safe_malloc(total_len + 1);
	current = *input;
	copy_unquoted_content(&current, result);
	*input = current;
	return (result);
}

char	*extract_quote(char **input)
{
	char	*quoted_str;

	if (!check_surroundings((const char **)input))
		quoted_str = take_quote(input);
	else
		quoted_str = extract_quote_util(input);
	return (quoted_str);
}

static bool	extract_operator_util(char **input)
{
	int	i;

	i = 0;
	while ((*input)[i] == '*' && (*input)[i])
		i++;
	if (i > 1)
	{
		ft_dprintf(2, "syntax error near unexpected token `*'\n");
		while (ft_strchr("*", **input) && **input)
			(*input)++;
		return (false);
	}
	else if (ft_strchr("|&*<>", **input) && **input)
	{
		ft_dprintf(2, "syntax error near unexpected token `%c'\n", **input);
		while (ft_strchr("|&*<>", **input) && **input)
			(*input)++;
		return (false);
	}
	return (true);
}

char	*extract_operator(char **input, t_shell *shell)
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
		shell->flag = false;
	operator = safe_malloc(sizeof(char) * (operator_size + 1));
	while (i < operator_size)
		operator[i++] = temp_char;
	operator[i] = '\0';
	return (operator);
}

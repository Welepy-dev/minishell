/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:45:43 by marcsilv          #+#    #+#             */
/*   Updated: 2025/04/04 15:13:03 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

char	*fill_quote(char **input, char quote, int i)
{
	char	*quote_string;
	char	*temp;

	temp = ft_strndup((*input) - i, i);
	quote_string = safe_malloc(sizeof(char) * (i + 3));
	quote_string[0] = quote;
	ft_strncpy(quote_string + 1, temp, i);
	quote_string[i + 1] = quote;
	quote_string[i + 2] = '\0';
	free(temp);
	return (quote_string);
}

/*size_t	calculate_unquoted_length(char **current_ptr)
{
	char	*current;
	char	quote;
	char	*chunk_start;
	size_t	total_len;

	total_len = 0;
	current = *current_ptr;
	while (*current && is_quote(*current))
	{
		quote = *current;
		current++;
		chunk_start = current;
		while (*current && *current != quote)
			current++;
		if (*current != quote)
			break ;
		total_len += current - chunk_start;
		current++;
	}
	*current_ptr = current;
	return (total_len);
}

void	copy_unquoted_content(char **current_ptr, char *dest)
{
	char	*current;
	char	quote;
	char	*chunk_start;
	int		chunk_len;
	int		i;

	current = *current_ptr;
	while (*current && is_quote(*current))
	{
		quote = *current;
		current++;
		chunk_start = current;
		while (*current && *current != quote)
			current++;
		if (*current != quote)
			break ;
		chunk_len = current - chunk_start;
		i = -1;
		while (++i < chunk_len)
			*dest++ = chunk_start[i];
		current++;
	}
	*current_ptr = current;
	*dest = '\0';
}

bool	check_surroundings(const char **input)
{
	const char	*start = *input;
	char		quote;

	quote = **input;
	(*input)++;
	while (**input && **input != quote)
		(*input)++;
	if (**input != quote)
	{
		*input = start;
		return (false);
	}
	(*input)++;
	if (**input != ' ' && !ft_isalnum(**input))
	{
		*input = start;
		return (false);
	}
	*input = start;
	return (true);
}*/

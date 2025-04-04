/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 17:45:43 by marcsilv          #+#    #+#             */
/*   Updated: 2025/04/02 15:35:31 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

size_t	calculate_unquoted_length(char **current_ptr)
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
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 16:12:38 by marcsilv          #+#    #+#             */
/*   Updated: 2025/04/02 16:19:53 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

static char	*find_quote_end(char **input, char quote)
{
	while (**input && **input != quote)
		(*input)++;
	return (*input);
}

static size_t	count_extra_chars(char **input)
{
	size_t	extra_len;

	extra_len = 0;
	while (**input && !ft_isspace(**input))
	{
		(*input)++;
		extra_len++;
	}
	return (extra_len);
}

static void	copy_quoted_content(char *result, const char *start,
	const char *end, bool include_quotes)
{
	int	i;

	i = -1;
	if (include_quotes)
	{
		while (++i <= end - start)
			result[i] = start[i];
		result[end - start + 1] = '\0';
	}
	else
	{
		while (++i < end - start - 1)
			result[i] = start[i + 1];
		result[end - start - 1] = '\0';
	}
}

static void	copy_extra_content(char *result, size_t len,
	const char *extra_start, size_t extra_len)
{
	size_t	i;

	i = 0;
	while (i < extra_len)
	{
		result[len + i] = extra_start[i];
		i++;
	}
	result[len + extra_len] = '\0';
}

char	*extract_quote_util(char **input)
{
	char	quote;
	char	*start;
	char	*end;
	char	*result;
	size_t	tab[2];

	quote = **input;
	start = *input;
	tab[1] = 0;
	(*input)++;
	end = find_quote_end(input, quote);
	if (*end != quote)
		return (NULL);
	(*input)++;
	tab[1] = count_extra_chars(input);
	if (tab[1] == 0)
		tab[0] = (end - start + 1);
	else
		tab[0] = (end - start - 1);
	result = safe_malloc(tab[0] + tab[1] + 1);
	copy_quoted_content(result, start, end, tab[1] == 0);
	if (tab[1] > 0)
		copy_extra_content(result, tab[0], end + 1, tab[1]);
	return (result);
}

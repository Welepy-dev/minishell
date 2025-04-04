/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 18:04:18 by welepy            #+#    #+#             */
/*   Updated: 2025/03/19 16:04:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	get_total_length(char **strings, const char *separator, int n)
{
	int		i;
	size_t	total_length;
	size_t	sep_length;

	if (separator)
		sep_length = ft_strlen(separator);
	else
		sep_length = 0;
	i = -1;
	while (++i < n)
	{
		if (strings[i])
		{
			total_length += ft_strlen(strings[i]);
			if (i < n - 1)
				total_length += sep_length;
		}
	}
	return (total_length);
}

char	*join_matrix(int n, char **strings, const char *separator)
{
	char	*result;
	int		i;

	if (n <= 0 || !strings)
		return (NULL);
	result = safe_malloc(get_total_length(strings, separator, n) + 1);
	result[0] = '\0';
	i = -1;
	while (++i < n)
	{
		if (strings[i])
		{
			ft_strcat(result, strings[i]);
			if (i < n - 1 && separator)
				ft_strcat(result, separator);
		}
	}
	return (result);
}

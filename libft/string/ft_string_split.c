/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:27:00 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/14 16:30:26 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_string_split(char *str, char c)
{
	char	*split;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	split = safe_malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != c)
	{
		split[i] = str[i];
		i++;
	}
	split[i] = '\0';
	return (split);
}

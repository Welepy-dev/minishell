/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_to_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:34:05 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/14 22:01:16 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*matrix_to_string(char **matrix)
{
	char	*str;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	while (matrix[i])
	{
		len += ft_strlen(matrix[i]);
		i++;
	}
	str = (char *)safe_malloc(sizeof(char) * (len + i));
	i = 0;
	j = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			str[j] = matrix[i][j];
			j++;
		}
		str[j] = ' ';
		i++;
	}
	str[j] = '\0';
	return (str);
}

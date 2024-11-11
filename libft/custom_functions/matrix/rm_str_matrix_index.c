/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_str_matrix_index.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:42:51 by welepy            #+#    #+#             */
/*   Updated: 2024/11/11 17:44:11 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**rm_str_matrix_index(char **matrix, int index)
{
	char	**new_matrix;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new_matrix = (char **)malloc(sizeof(char *) * (matrix_len(matrix)));
	if (!new_matrix)
		return (NULL);
	while (matrix[i])
	{
		if (i != index)
		{
			new_matrix[j] = ft_strdup(matrix[i]);
			j++;
		}
		i++;
	}
	new_matrix[j] = NULL;
	free_matrix(matrix);
	return (new_matrix);
}

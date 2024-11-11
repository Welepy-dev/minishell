/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_str_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:36:31 by welepy            #+#    #+#             */
/*   Updated: 2024/11/11 17:42:15 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**add_str_matrix(char **matrix, char *str)
{
	char	**new_matrix;
	int		i;

	i = 0;
	new_matrix = (char **)malloc(sizeof(char *) * (matrix_len(matrix) + 2));
	if (!new_matrix)
		return (NULL);
	while (matrix[i])
	{
		new_matrix[i] = ft_strdup(matrix[i]);
		i++;
	}
	new_matrix[i] = ft_strdup(str);
	new_matrix[i + 1] = NULL;
	free_matrix(matrix);
	return (new_matrix);
}
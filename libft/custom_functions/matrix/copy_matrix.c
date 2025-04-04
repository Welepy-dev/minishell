/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:25:46 by welepy            #+#    #+#             */
/*   Updated: 2024/11/13 09:48:30 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	**copy_matrix(char **matrix)
{
	char	**new_matrix;
	int		i;

	i = 0;
	new_matrix = (char **)malloc(sizeof(char *) * (matrix_len(matrix) + 1));
	if (!new_matrix)
		return (NULL);
	while (matrix[i])
	{
		new_matrix[i] = ft_strdup(matrix[i]);
		i++;
	}
	new_matrix[i] = NULL;
	return (new_matrix);
}

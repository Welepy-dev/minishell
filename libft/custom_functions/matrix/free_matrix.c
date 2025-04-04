/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:30:54 by marcsilv          #+#    #+#             */
/*   Updated: 2025/03/28 10:16:05 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	free_matrix(char **matrix)
{
	int	i;

	if (matrix && !matrix[0])
	{
		i = 0;
		while (matrix[i])
		{
			ft_free(&matrix[i]);
			i++;
		}
		free(matrix);
		matrix = NULL;
	}
}

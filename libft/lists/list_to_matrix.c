/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_to_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:13:17 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/13 14:23:38 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

char	**list_to_matrix(t_list *list)
{
	char	**matrix;
	t_list	*tmp;
	int		i;

	matrix = malloc(sizeof(char *) * (ft_lstsize(list) + 1));
	if (!matrix)
		return (NULL);
	i = 0;
	tmp = list;
	while (tmp)
	{
		matrix[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	matrix[i] = NULL;
	return (matrix);
}

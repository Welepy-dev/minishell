/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:09:51 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/28 16:07:19 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*matrix_to_list(char **matrix)
{
	t_list	*list;
	t_list	*new;
	int		i;

	list = NULL;
	i = 0;
	while (matrix[i])
	{
		new = ft_lstnew(matrix[i]);
		if (!new)
		{
			ft_lstclear(&list, free);
			return (NULL);
		}
		ft_lstadd_back(&list, new);
		i++;
	}
	return (list);
}

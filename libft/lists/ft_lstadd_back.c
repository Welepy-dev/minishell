/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:58:38 by marcsilv          #+#    #+#             */
/*   Updated: 2025/03/14 18:08:05 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstadd_back(t_list **alst, t_list *new_node)
{
	t_list	*t;

	if (*alst)
	{
		t = ft_lstlast(*alst);
		t->next = &*new_node;
	}
	else
		*alst = new_node;
}

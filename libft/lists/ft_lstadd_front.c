/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 12:47:15 by marcsilv          #+#    #+#             */
/*   Updated: 2025/03/14 18:09:16 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstadd_front(t_list **alst, t_list *new_node)
{
	if (!alst || !new_node)
		return ;
	new_node->next = *alst;
	*alst = new_node;
}

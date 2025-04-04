/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:16:10 by marcsilv          #+#    #+#             */
/*   Updated: 2024/12/11 15:11:24 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

static void	swap(t_list *a, t_list *b)
{
	void	*tmp;

	tmp = a->content;
	a->content = b->content;
	b->content = tmp;
}

static t_list	*partition(t_list *low, t_list *high,
			int (*cmp)(void *, void *))
{
	void	*pivot;
	t_list	*i;
	t_list	*j;

	pivot = high->content;
	i = low->prev;
	j = low;
	while (j != high)
	{
		if (cmp(j->content, pivot) < 0)
		{
			if (i == NULL)
				i = low;
			else
				i = i->next;
			swap(i, j);
		}
		j = j->next;
	}
	if (i == NULL)
		i = low;
	else
		i = i->next;
	swap(i, high);
	return (i);
}

static void	quick_sort(t_list *low, t_list *high, int (*cmp)(void *, void *))
{
	t_list	*pivot;

	if (high != NULL && low != high && low != high->next)
	{
		pivot = partition(low, high, cmp);
		quick_sort(low, pivot->prev, cmp);
		quick_sort(pivot->next, high, cmp);
	}
}

void	qsort_list(t_list *list, int (*cmp)(void *, void *))
{
	t_list	*last;

	last = list;
	while (last->next != NULL)
		last = last->next;
	quick_sort(list, last, cmp);
}

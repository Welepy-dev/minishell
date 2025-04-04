/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_quicksort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:20:18 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/13 10:56:43 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	*r_quicksort(int *tab, unsigned int size)
{
	unsigned int	i;
	int				temp;

	i = 0;
	temp = 0;
	while (i < (size - 1))
	{
		if (tab[i] < tab[i + 1])
		{
			temp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	return (tab);
}

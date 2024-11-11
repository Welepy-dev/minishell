/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:11:50 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/11 13:44:40 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	size_max;

	size_max = 4294967295;
	if (count == 0 || size == 0)
		return (malloc(1));
	if (count > size_max / size)
		return (NULL);
	ptr = malloc(count * size);
	ft_bzero(ptr, size * count);
	return (ptr);
}

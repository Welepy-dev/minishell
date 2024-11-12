/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:39:42 by welepy            #+#    #+#             */
/*   Updated: 2024/11/12 14:15:57 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*new_ptr;

	new_ptr = malloc(size);
	if (!new_ptr)
	{
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}
	ft_memcpy(new_ptr, ptr, size);
	free(ptr);
	return (new_ptr);
}

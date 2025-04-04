/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 15:06:35 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/11 18:24:04 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *s, const char *a, size_t n)
{
	size_t	a_len;

	a_len = ft_strlen(a);
	if (*a == '\0')
		return ((char *)s);
	while (*s != '\0' && n >= a_len)
	{
		if (*s == *a && ft_strncmp(s, a, a_len) == 0)
			return ((char *)s);
		s++;
		n--;
	}
	return (NULL);
}

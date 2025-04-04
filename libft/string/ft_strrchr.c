/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 18:36:05 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/11 18:24:04 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned char	uc;
	const char		*last;

	uc = (unsigned char)c;
	last = NULL;
	while (*str != '\0')
	{
		if (*str == uc)
			last = str;
		str++;
	}
	if (*str == uc)
		last = str;
	return ((char *)last);
}

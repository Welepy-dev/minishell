/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 16:59:11 by marcsilv          #+#    #+#             */
/*   Updated: 2025/03/09 12:45:54 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;

	if (!s)
		return (NULL);
	len = ft_strlen(s) + 1;
	dup = safe_malloc(len);
	if (dup == NULL)
		return (NULL);
	ft_memcpy(dup, s, len);
	return (dup);
}

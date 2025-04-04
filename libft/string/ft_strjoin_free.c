/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:02:24 by marcsilv          #+#    #+#             */
/*   Updated: 2025/03/12 15:51:51 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin_free(char *s1, char *s2, char flag)
{
	size_t		len1;
	size_t		len2;
	char		*result;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = (char *)malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	ft_strncpy(result, s1, len1);
	ft_strncpy(result + len1, s2, len2 + 1);
	if (flag == 1 || flag == 3)
		free(s1);
	if (flag == 2 || flag == 3)
		free(s2);
	return (result);
}

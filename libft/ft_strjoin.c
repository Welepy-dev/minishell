/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:07:07 by marcsilv          #+#    #+#             */
/*   Updated: 2024/05/18 13:34:32 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		saco1;
	int		saco2;
	char	*bigbox;

	saco1 = 0;
	saco2 = 0;
	bigbox = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (bigbox == NULL)
		return (NULL);
	while (s1[saco1] != '\0')
	{
		bigbox[saco1] = s1[saco1];
		saco1++;
	}
	while (s2[saco2] != '\0')
	{
		bigbox[ft_strlen(s1) + saco2] = s2[saco2];
		saco2++;
	}
	bigbox[ft_strlen(s1) + saco2] = '\0';
	return (bigbox);
}

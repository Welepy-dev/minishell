/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 13:39:46 by marcsilv          #+#    #+#             */
/*   Updated: 2025/03/15 15:14:20 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	int	i;
	int	j;

	j = ft_strlen(s1) - 1;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && ft_strchr(set, s1[i]))
		i++;
	while (j >= 0 && ft_strchr(set, s1[j]))
		j--;
	if (i > j)
		return (ft_strdup(""));
	return (ft_substr(s1, i, j - i + 1));
}
/*removes characters from s1 that are present in set*/
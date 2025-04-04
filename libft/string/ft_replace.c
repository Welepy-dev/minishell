/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:35:39 by marcsilv          #+#    #+#             */
/*   Updated: 2025/03/07 10:04:16 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_replace(const char *str, const char *new_word, int index)
{
	int		end_index;
	int		replace_word_len;
	int		new_str_len;
	char	*result;

	end_index = index;
	if (!str || !new_word || index < 0 || index >= (int)ft_strlen(str))
		return (NULL);
	while (str[end_index] != ' ' && str[end_index] != '\0')
		end_index++;
	replace_word_len = end_index - index;
	new_str_len = ft_strlen(str) - replace_word_len + ft_strlen(new_word);
	result = (char *)malloc(new_str_len + 1);
	if (!result)
		return (NULL);
	ft_strncpy(result, str, index);
	result[index] = '\0';
	ft_strcat(result, new_word);
	ft_strcat(result, str + end_index);
	return (result);
}

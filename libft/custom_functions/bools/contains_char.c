/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contains_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 12:52:18 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/13 12:54:11 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

bool	contains_char(char *str, char *set)
{
	while (*str)
	{
		if (ft_strchr(set, *str))
			return (true);
		str++;
	}
	return (false);
}

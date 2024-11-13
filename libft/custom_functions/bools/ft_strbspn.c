/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:03:09 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/13 16:04:56 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

bool	ft_strbspn(char *str, char accept)
{
	while (*str)
	{
		if (*str != accept)
			return (false);
		++str;
	}
	return(true);
}
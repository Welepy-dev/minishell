/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 10:32:51 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/11 18:17:51 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

bool inline	ft_isalpha(int c)
{
	return (ft_islower(c) || ft_isupper(c));
}
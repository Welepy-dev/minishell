/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:53:20 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/11 13:54:25 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double	ft_pow(double base, double exp)
{
	double	result;

	result = 1;
	while (exp)
	{
		if (exp < 0)
		{
			result /= base;
			exp++;
		}
		else
		{
			result *= base;
			exp--;
		}
	}
	return (result);
}

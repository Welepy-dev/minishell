/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:50:06 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/11 13:59:22 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static double	ft_pow(double base, int exp)
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

static int	ft_atoi(const char *str, double num, int i)
{
	while (ft_isdigit(str[i]))
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (num);
}

double	ft_atof(const char *str)
{
	double	num;
	double	decimal;
	int		isneg;
	int		i;

	num = 0;
	decimal = 0;
	isneg = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		isneg *= -1;
		i++;
	}
	num = ft_atoi(str, num, i);
	if (str[i] == '.')
	{
		i++;
		ft_atoi(str, decimal, i);
	}
	return ((num + (decimal / ft_pow(10, i))) * isneg);
}
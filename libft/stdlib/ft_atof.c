/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:50:06 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/12 19:09:05 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static double	a_p(double base, int exp)
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

static int	convert(const char *str, double num, int i)
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
	num = convert(str, num, i);
	if (str[i] == '.')
	{
		i++;
		convert(str, decimal, i);
	}
	return ((num + (decimal / a_p(10, i))) * isneg);
}

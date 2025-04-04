/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:10:17 by welepy            #+#    #+#             */
/*   Updated: 2024/11/13 10:31:39 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_print_ptr(unsigned long long *ptr)
{
	int					len;
	unsigned long long	pointer;

	len = 0;
	pointer = (unsigned long long)ptr;
	len += ft_putstr("0x");
	if (pointer == 0)
		len += ft_putchar('0');
	else
		len += lower(pointer);
	return (len);
}

int	ft_print_unsigned(unsigned int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len += ft_putchar('0');
	else
		len += lower(n);
	return (len);
}

int	ft_putnbr(int n)
{
	int	len;

	len = 0;
	if (n == INT_MIN)
	{
		len += ft_putstr("-2147483648");
		return (len);
	}
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		len += ft_putnbr(n / 10);
	len += ft_putchar(n % 10 + '0');
	return (len);
}

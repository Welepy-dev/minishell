/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:07:07 by welepy            #+#    #+#             */
/*   Updated: 2024/11/13 10:29:48 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	lower(unsigned int decimalnumber)
{
	char	hexnumber[32];
	int		i;
	int		reverse_i;

	i = 0;
	if (decimalnumber == 0)
		return (ft_putchar('0'), 1);
	while (decimalnumber)
	{
		hexnumber[i++] = "0123456789abcdef"[decimalnumber % 16];
		decimalnumber /= 16;
	}
	reverse_i = i - 1;
	while (reverse_i >= 0)
	{
		ft_putchar(hexnumber[reverse_i]);
		reverse_i--;
	}
	return (i);
}

int	upper(unsigned int decimalnumber)
{
	char	hexnumber[32];
	int		i;
	int		reverse_i;
	int		remainder;

	i = 0;
	if (decimalnumber == 0)
		return (ft_putchar('0'), 1);
	while (decimalnumber != 0)
	{
		remainder = decimalnumber % 16;
		if (remainder < 10)
			hexnumber[i++] = 48 + remainder;
		else
			hexnumber[i++] = 55 + remainder;
		decimalnumber /= 16;
	}
	reverse_i = i - 1;
	while (reverse_i >= 0)
	{
		ft_putchar(hexnumber[reverse_i]);
		reverse_i--;
	}
	return (i);
}

int	find_specifier(char my_string, va_list args)
{
	int	length;

	length = 0;
	if (my_string == 'c')
		length += ft_putchar(va_arg(args, int));
	else if (my_string == 's')
		length += ft_putstr(va_arg(args, char *));
	else if (my_string == 'p')
		length += ft_print_ptr(va_arg(args, unsigned long long *));
	else if (my_string == 'd' || my_string == 'i')
		length += ft_putnbr(va_arg(args, int));
	else if (my_string == 'u')
		length += ft_print_unsigned(va_arg(args, unsigned int));
	else if (my_string == 'x')
		length += lower(va_arg(args, unsigned int));
	else if (my_string == 'X')
		length += upper(va_arg(args, unsigned int));
	else if (my_string == '%')
		length += ft_putchar('%');
	return (length);
}

int	ft_printf(const char *my_string, ...)
{
	int		length;
	int		i;
	va_list	args;

	i = 0;
	length = 0;
	va_start(args, my_string);
	while (my_string[i] != '\0')
	{
		if (my_string[i] == '%')
		{
			length += find_specifier(my_string[i + 1], args);
			i++;
		}
		else
			length += ft_putchar(my_string[i]);
		i++;
	}
	va_end (args);
	return (length);
}

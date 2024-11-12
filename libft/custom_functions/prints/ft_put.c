/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 14:10:17 by welepy            #+#    #+#             */
/*   Updated: 2024/11/12 14:15:04 by welepy           ###   ########.fr       */
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
int	ft_print_ptr(void *ptr)
{
	int	len;

	len = 0;
	unsigned long long	pointer;

	pointer = (unsigned long long)ptr;
	len += ft_putstr("0x");
	if (pointer == 0)
		len += ft_putchar('0');
	else
		len += lower(pointer);
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
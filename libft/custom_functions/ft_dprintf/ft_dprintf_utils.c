/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:02:30 by efinda            #+#    #+#             */
/*   Updated: 2025/03/18 14:18:52 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	ft_fputchar(int fd, char c, int *res)
{
	write(fd, &c, 1);
	(*res)++;
}

void	ft_fputstr(int fd, char *s, int *res)
{
	if (!s)
		ft_fputstr(fd, "(null)", res);
	else
	{
		while (*s)
		{
			ft_fputchar(fd, *s, res);
			s++;
		}
	}
}

void	ft_fputnbr(int fd, int nbr, int *res)
{
	if (nbr == INT_MAX)
		ft_fputstr(fd, "-2147483648", res);
	else if (nbr < 0)
	{
		ft_fputchar(fd, '-', res);
		nbr *= -1;
		ft_fputnbr(fd, nbr, res);
	}
	else if (nbr > 9)
	{
		ft_fputnbr(fd, (nbr / 10), res);
		ft_fputchar(fd, ((nbr % 10) + 48), res);
	}
	else
		ft_fputchar(fd, (nbr + 48), res);
}

void	ft_fprintbase(int fd, unsigned long long nbr, char *simbol,
			int *res)
{
	if (nbr >= 16)
		ft_fprintbase(fd, nbr / 16, simbol, res);
	ft_fputchar(fd, simbol[nbr % 16], res);
}

void	ft_fprintptr(int fd, void *ptr, int *res)
{
	unsigned long	p;

	p = (unsigned long)ptr;
	if (ptr)
	{
		ft_fputstr(fd, "0x", res);
		ft_fprintbase(fd, p, "0123456789abcdef", res);
	}
	else
		ft_fputstr(fd, "(nil)", res);
}

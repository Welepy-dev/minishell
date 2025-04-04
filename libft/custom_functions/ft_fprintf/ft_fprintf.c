/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/07 13:01:32 by efinda            #+#    #+#             */
/*   Updated: 2024/11/15 15:49:32 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static	void	ft_fcheck_identif(va_list args, int fd, const char *s, int *res)
{
	if (*s == 'c')
		ft_fputchar(fd, va_arg(args, int), res);
	else if (*s == 's')
		ft_fputstr(fd, va_arg(args, char *), res);
	else if (*s == 'd' || *s == 'i')
		ft_fputnbr(fd, va_arg(args, int), res);
	else if (*s == 'x')
	{
		ft_fprintbase(fd, va_arg(args, unsigned int),
			"0123456789abcdef", res);
	}
	else if (*s == 'X')
	{
		ft_fprintbase(fd, va_arg(args, unsigned int),
			"0123456789ABCDEF", res);
	}
	else if (*s == 'p')
		ft_fprintptr(fd, va_arg(args, void *), res);
	else if (*s == '%')
		ft_fputchar(fd, *s, res);
}

int	ft_fprintf(int fd, const char *str, ...)
{
	int			res;
	va_list		args;

	va_start(args, str);
	res = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_fcheck_identif(args, fd, str, &res);
		}
		else
			ft_fputchar(fd, *str, &res);
		str++;
	}
	va_end(args);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 14:00:34 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/24 17:58:03 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

bool	is_builtin_or_command(t_type type)
{
	return (type == COMMAND || type == BUILTINS || type == FULL_COMMAND);
}

bool	is_builtin(t_type type)
{
	return (type == BUILTINS);
}

bool	ft_atol_util(const char *str)
{
	if (ft_strlen(str) > 20)
		return (true);
	while (ft_isdigit(*str))
		str++;
	if (*str != '\0')
		return (true);
	return (false);
}

long long	ft_atol(const char *str)
{
	long				signal;
	unsigned long long	number;

	number = 0;
	signal = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signal = -1;
		str++;
	}
	if (ft_atol_util(str))
		return (939552403);
	while (ft_isdigit(*str))
	{
		number = (number * 10) + (*str - 48);
		str++;
	}
	if ((signal == 1 && number > LONG_MAX)
		|| (signal == -1 && number > (unsigned long long)LONG_MAX + 1))
		return (939552403);
	return (number * signal);
}

int	redirections_error_handler(t_token *token)
{
	if (!token || !token->next || token->next->type == PIPE
		|| token->next->type == APPEND || token->next->type == HERE_DOC
		|| token->next->type == GREATER || token->next->type == LESSER)
		return (1);
	return (0);
}

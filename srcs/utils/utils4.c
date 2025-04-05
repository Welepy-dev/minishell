/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:13:26 by marcsilv          #+#    #+#             */
/*   Updated: 2025/04/03 18:25:02 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

bool	is_quote(char c)
{
	if (c)
		return (c == '\'' || c == '\"');
	return (false);
}

int	expand_flag(char *input, int i)
{
	if (input[i] == '\'')
		return (-1);
	return (1);
}

void	error_quote(t_shell *shell)
{
	if (!validate_quote_number(shell->input))
	{
		ft_dprintf(2, "Error: can't parse unclosed quotes\n");
		shell->flag = false;
	}
}

bool	command_quote(char *str)
{
	int		i;
	char	quote;

	if (!str || !*str)
		return (false);
	if (*str != '\'' && *str != '\"')
		return (false);
	quote = *str;
	i = 1;
	while (str[i])
	{
		if (str[i] == quote)
			return (true);
		i++;
	}
	return (false);
}

bool	is_char_operator(char c)
{
	if (c)
		return (c == '&' || c == '|' || c == '>' || c == '<');
	return (false);
}

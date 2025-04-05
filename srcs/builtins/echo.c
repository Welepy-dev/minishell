/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:48:53 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/04 15:10:40 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

static bool	check_input(char *input)
{
	char	*single_q;
	char	*double_q;

	single_q = ft_strchr(input, '\'');
	double_q = ft_strchr(input, '\"');
	if (single_q)
	{
		single_q--;
		if (!ft_isspace(*single_q))
			return (true);
	}
	else if (double_q)
	{
		double_q--;
		if (!ft_isspace(*double_q))
			return (true);
	}
	return (false);
}

static void	echo_aux_ext(t_token *temp, bool *tab)
{
	char	*str;

	if (!tab[0] && !tab[1])
		printf(" ");
	tab[0] = false;
	if (temp->value)
	{
		str = remove_quotes(temp->value, false);
		printf("%s", str);
		ft_free(&str);
	}
}

bool	echo_aux(t_token *token, bool *option, char *input)
{
	t_token	*temp;
	bool	*tab;

	tab = (bool []){true, check_input(input)};
	temp = token->next;
	handle_options(&temp, option);
	handle_arguments(temp);
	while (temp)
	{
		if (temp->type == ARGUMENT || temp->type == SINGLE_QUOTE
			|| temp->type == DOUBLE_QUOTE || temp->type == OPTION)
			echo_aux_ext(temp, tab);
		else if (is_redirection(temp->type))
			handle_redirections(&temp);
		else
			break ;
		temp = temp->next;
	}
	return (*option);
}

void	ft_echo(t_token *token, t_shell *shell)
{
	bool	option;

	option = false;
	if (!token)
	{
		write(1, "\n", 1);
		return ;
	}
	option = echo_aux(token, &option, (shell->input));
	if (!option)
		printf("\n");
	shell->exit_status = 0;
}

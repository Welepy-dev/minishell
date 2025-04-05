/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 15:26:37 by welepy            #+#    #+#             */
/*   Updated: 2025/03/23 16:50:39 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

static bool	v_option(char *value)
{
	int	i;

	if (value[0] != '-')
		return (false);
	if (value[1] == '\0')
		return (false);
	i = 1;
	while (value[i])
	{
		if (value[i] != 'n')
			return (false);
		i++;
	}
	return (true);
}

void	handle_options(t_token **temp, bool *option)
{
	while (*temp && ((*temp)->type == OPTION || (*temp)->type == SINGLE_QUOTE
			|| (*temp)->type == DOUBLE_QUOTE) && v_option((*temp)->value))
	{
		*option = true;
		*temp = (*temp)->next;
	}
}

void	handle_arguments(t_token *temp)
{
	while (temp && temp->type == OPTION)
	{
		temp->type = ARGUMENT;
		temp = temp->next;
	}
}

void	handle_redirections(t_token **temp)
{
	while (*temp && is_redirection((*temp)->type))
	{
		*temp = (*temp)->next;
		if (*temp)
			*temp = (*temp)->next;
	}
}

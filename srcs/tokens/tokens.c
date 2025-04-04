/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:53:06 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/29 17:51:16 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

int	builtins_type(char *value)
{
	if (ft_strcmp(value, "echo") == 0)
		return (1);
	else if (ft_strcmp(value, "cd") == 0)
		return (1);
	else if (ft_strcmp(value, "pwd") == 0)
		return (1);
	else if (ft_strcmp(value, "env") == 0)
		return (1);
	else if (ft_strcmp(value, "export") == 0)
		return (1);
	else if (ft_strcmp(value, "unset") == 0)
		return (1);
	else if (ft_strcmp(value, "exit") == 0)
		return (1);
	return (0);
}

t_type	find_type(char *value)
{
	if (!ft_strcmp(value, ">"))
		return (GREATER);
	else if (!ft_strcmp(value, "<"))
		return (LESSER);
	else if (!ft_strcmp(value, ">>"))
		return (APPEND);
	else if (!ft_strcmp(value, "<<"))
		return (HERE_DOC);
	else if (!ft_strcmp(value, "|"))
		return (PIPE);
	else if (builtins_type(value))
		return (BUILTINS);
	else if (value[0] == '\'')
		return (SINGLE_QUOTE);
	else if (value[0] == '\"')
		return (DOUBLE_QUOTE);
	else if (value[0] == '-')
		return (OPTION);
	else
		return (IDENTIFIER);
}

t_token	*tokenize_array(char **array)
{
	int		i;
	char	*str;
	t_token	*new;
	t_token	*token;

	i = 0;
	token = NULL;
	while (array[i])
	{
		str = remove_quotes(array[i]);
		new = new_token(str, find_type(array[i]));
		ft_lstadd_back((t_list **)&token, (t_list *)new);
		i++;
		ft_free(&str);
	}
	return (token);
}

void	identify_tokens(t_token *tokens)
{
	t_token	*head;
	char	*temp;

	head = tokens;
	while (head)
	{
		temp = ft_strjoin("/bin/", head->value);
		if (head->type == IDENTIFIER)
		{
			if (access(temp, F_OK) == 0)
				head->type = COMMAND;
			else if (access(head->value, F_OK) == 0)
				head->type = FULL_COMMAND;
			else
				head->type = ARGUMENT;
		}
		ft_free(&temp);
		head = head->next;
	}
}

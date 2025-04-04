/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 14:13:26 by marcsilv          #+#    #+#             */
/*   Updated: 2025/04/02 16:27:54 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

bool	is_quote(char c)
{
	return (c == '\'' || c == '\"');
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

t_env	*last_env(t_env *env)
{
	if (env == NULL)
		return (NULL);
	while (env->next != NULL)
		env = env->next;
	return (env);
}

void	add_env(t_env **env, t_env *new)
{
	t_env	*t;

	if (*env)
	{
		t = last_env(*env);
		t->next = new;
	}
	else
		*env = new;
}

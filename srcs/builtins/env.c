/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:48:58 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/22 18:53:23 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

void	ft_env(t_env *env, t_token *token, t_shell *shell, bool declare)
{
	t_env	*tmp;

	tmp = env;
	if (token->next && (token->next->type == ARGUMENT
			|| token->next->type == OPTION))
	{
		ft_dprintf(2, "env: this env does not support options or arguments\n");
		shell->exit_status = 1;
		return ;
	}
	while (tmp)
	{
		if (declare)
			printf("declare -x ");
		printf("%s=", tmp->name);
		if (tmp->value)
			printf("%s", tmp->value);
		printf("\n");
		tmp = tmp->next;
	}
	shell->exit_status = 0;
}

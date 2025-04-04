/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 15:49:13 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/15 17:55:07 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

void	ft_pwd(t_token *current, t_shell *shell)
{
	char		*pwd;
	t_token		*token;

	token = current->next;
	if (token && (token->type == OPTION))
	{
		printf("pwd: this version does not supports options\n");
		shell->exit_status = 1;
		return ;
	}
	pwd = safe_malloc(PATH_MAX);
	if (getcwd(pwd, PATH_MAX) == NULL)
	{
		perror("getcwd");
		ft_free(&pwd);
		shell->exit_status = 1;
	}
	else
	{
		printf("%s\n", pwd);
		ft_free(&pwd);
		shell->exit_status = 0;
	}
}

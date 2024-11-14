/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:37:07 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/14 21:47:21 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	*search_env(char **matrix)
{
	int	y;
	int	x;
	int	x;
	int	var_num;
	int	*tab;

	y = 0;
	x = 0;
	var_num = 0;
	while (matrix[y])
	{
		if (matrix[y][0] == '$')
			var_num++;
		y++;
	}
	tab = (int *)safe_malloc(sizeof(int) * (var_num + 1));
	y = 0;
	while (matrix[y])
	{
		if (matrix[y][0] == '$')
			tab[x++] = y;
		y++;
	}
	return (tab);
}

void	expand(char ***matrix, t_env)
{

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:05:06 by welepy            #+#    #+#             */
/*   Updated: 2024/11/14 22:01:28 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	clean_and_exit(t_generic *data)
{
	if (data->input)
		free(data->input);
	if (data->matrix)
		free_matrix(data->matrix);
	if (data->env)
		ft_lstclear((t_list **)&data->env, free);
	exit(0);
}

/*
	shell->input
	shell->matrix (also each word)
	temp string at extract_quote
	tab at search_env
*/
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:05:06 by welepy            #+#    #+#             */
/*   Updated: 2024/11/13 15:54:20 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	clean_and_exit(t_generic *data)
{
	// if (data)
	// 	free(data);
	if (data->input)
		free(data->input);
	if (data->matrix)
		free_matrix(data->matrix);
	exit(1);
}

/*
	shell->input
	shell->matrix (also each word)
	
*/
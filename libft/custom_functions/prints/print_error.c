/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:56:42 by welepy            #+#    #+#             */
/*   Updated: 2024/11/12 17:05:25 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	print_error(char *error_message, void *data)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(error_message, 2);
	if (data)
		clean_and_exit(data);
	else
		exit(1);
}

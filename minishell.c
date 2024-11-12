/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:22:46 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/12 15:28:42 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	(void)av;
	if (ac != 1)
	{
		ft_putendl_fd("Error: too many arguments", 2);
		return (1);
	}
	t_shell	shell;

	//initialize shell
	//read the input

	//parse the input
		//tokenize the input
		//parse the tokens
	//execute the command
	//repeat

	while (1)
	{
		readline("minishell$ ");

	}
}

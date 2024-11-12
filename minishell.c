/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:22:46 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/12 16:45:46 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_shell	shell;
	
	(void)av;
	if (ac != 1)
	{
		ft_putendl_fd("Error: too many arguments", 2);
		return (1);
	}

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

/*search what are valid token orders
  search how to tokenize a string
  search how to parse a string
  search how to execute a command
  search how to read a line

*/
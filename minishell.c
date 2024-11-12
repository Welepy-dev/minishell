/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:22:46 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/12 18:07:15 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int ac, char **av, char **env)
{
	t_shell	shell;
	
	(void)av;
	(void)env;
	if (ac != 1)
		print_error("Error: too many arguments", &shell);

	//initialize shell
	//read the input
	while (1)
	{
		shell.input = readline("minishell$ ");
		if (!shell.input)
			break ;
		ft_printf("input: %s\n", shell.input);
		//parse the input
			//tokenize the input
			//parse the tokens
		

	}
	//execute the command
	//repeat
	return (0);
}

/*search what are valid token orders
  search how to tokenize a string
  search how to parse a string
  search how to execute a command
  search how to read a line
  search expansion
when ctrl + D is pressed, exit the program
when ctrl + C is send a signal to cancel the current command
when ctrl + \ is pressed, do nothing
*/


/*looks first for commands or redirections*/
/*if the first token is a '*' will have the default behaviour of the shell
if is a'$' first expands it and sees if is a command if not, writes command not found*/
/*if is a ctrl command does the work accordingly*/


/*struct named tokens: will have command arguments and operators*/
/*to tokenize:
skip unnecessary whitespace*/
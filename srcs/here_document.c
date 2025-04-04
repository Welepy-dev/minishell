/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_document.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:56:07 by mchingi           #+#    #+#             */
/*   Updated: 2025/03/24 17:31:51 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minihell.h"

volatile sig_atomic_t	g_interrupted = 0;

void	sigint_handler_here_doc(int sig)
{
	(void)sig;
	g_interrupted = 1;
	close(STDIN_FILENO);
}

void	read_input_and_write_to_file(int fd, char *delimeter)
{
	char	*input;

	while (1)
	{
		input = readline("> ");
		if (!input || ft_strcmp(input, delimeter) == 0)
		{
			free(input);
			break ;
		}
		if (*input)
			add_history(input);
		write(fd, input, ft_strlen(input));
		write(fd, "\n", 1);
		free (input);
	}
}

void	here_doc(char *str)
{
	int					fd;
	char				*delimeter;
	struct sigaction	sa;

	delimeter = ft_strdup(str);
	fd = open(".DOC_TMP", O_WRONLY | O_TRUNC | O_CREAT, 0644);
	sa.sa_handler = sigint_handler_here_doc;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGINT, &sa, NULL);
	read_input_and_write_to_file(fd, delimeter);
	close(fd);
	free(delimeter);
	sa.sa_handler = SIG_DFL;
	sigaction(SIGINT, &sa, NULL);
	if (g_interrupted)
	{
		unlink(".DOC_TMP");
		exit(130);
	}
}

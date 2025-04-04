/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchingi <mchingi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:32:01 by marcsilv          #+#    #+#             */
/*   Updated: 2025/03/24 23:55:13 by mchingi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minihell.h"

extern volatile sig_atomic_t	g_sigint;
extern volatile sig_atomic_t	g_interrupted;

void	set_sigint(int *num, char write)
{
	static int	*sig;

	if (!sig)
		sig = num;
	else if (write)
		*sig = 130;
}

void	signal_handler(int sig)
{
	char	*cwd;

	cwd = safe_malloc(PATH_MAX);
	getcwd(cwd, PATH_MAX);
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		printf("┌[%s] - [%s]\n", getenv("USER"), cwd);
		set_sigint(NULL, 1);
		rl_redisplay();
	}
	ft_free(&cwd);
}

void	process_signal_handler(int sig)
{
	(void) sig;
	printf("\n");
}

int	exit_status_signal(int exit_status)
{
	if (WIFEXITED(exit_status))
		return (WEXITSTATUS(exit_status));
	else if (WIFSIGNALED(exit_status))
		return (WTERMSIG(exit_status) + 128);
	return (exit_status);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: welepy <welepy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:21:36 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/12 18:15:21 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_shell	t_shell;

typedef enum	e_type
{
	COMMAND,
	ARGUMENT,
	OPERATOR,
	REDIRECTION,
	VARIABLE,
	SIGNAL,
}	t_type;

typedef struct s_token
{
	char	*value;
	t_type	type;
    	struct s_token *next;
}	t_token;

typedef struct s_tree
{
	t_shell	*shell;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

struct s_shell
{
	t_token	*token;
	t_tree	*tree;
	char	**matrix;
	char	*input;
};

#endif
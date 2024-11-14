/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:21:36 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/14 17:37:49 by marcsilv         ###   ########.fr       */
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

typedef enum e_type
{
	COMMAND,
	ARGUMENT,
	OPERATOR,
	REDIRECTION,
	VARIABLE,
	SIGNAL,
	SINGLE_QUOTE,
	DOUBLE_QUOTE,
}	t_type;

typedef struct s_token
{
	char			*value;
	t_type			type;
	struct s_token	*next;
}	t_token;

typedef struct s_tree
{
	t_shell			*shell;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

struct s_shell
{
	t_token	*token;
	t_tree	*tree;
	t_env	*env;
	char	**matrix;
	char	*input;
};

char	**split_input(char *input);
char	*extract_variable(char **input);
char	*fill_quote(char **input, char quote, int i);

bool	validate_quote_number(char *input);
bool	extract_operator_util(char **input);

int		word_count_util(char *i, int count);
int		count_quote(char *input, char quote);

t_env	*convert_env(char **env);

#endif
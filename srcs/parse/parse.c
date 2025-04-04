/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:47:02 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/03 10:07:00 by welepy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

char  *remove_inside_quotes(char *command)
{
	char	*unquoted_command;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (j < ft_strlen(command))
	{
		if (command[j] != '\'' && command[j] != '\"')
			i++;
		j++;
	}
	unquoted_command = safe_malloc(sizeof(char) * (i + 1));
	i = 0;
	j = 0;
	while (j < ft_strlen(command))
	{
		if (command[j] != '\'' && command[j] != '\"')
			unquoted_command[i++] = command[j];
		j++;
	}
	unquoted_command[i] = '\0';
	ft_free(&command);
	return (unquoted_command);
}

static char	*extract_command(char **input)
{
	char	*command;
	int		i;

	i = 0;
	while (**input && !ft_isspace(**input) && !ft_strchr("|<>«»&*", **input))
	{
		i++;
		(*input)++;
	}
	command = ft_strndup((*input) - i, i);
	return (remove_inside_quotes(command));
}

static char	*extract_variable(char **input)
{
	char	*variable;
	int		i;
	char	*temp;

	i = 0;
	(*input)++;
	while (**input && (!ft_isspace(**input) && **input != '<'
			&& **input != '>' && **input != '|'
			&& **input != '*' && **input != '&'))
	{
		i++;
		(*input)++;
	}
	temp = ft_strndup((*input) - i, i);
	variable = safe_malloc(sizeof(char) * (i + 2));
	variable[0] = '$';
	ft_strncpy(variable + 1, temp, i);
	variable[i + 1] = '\0';
	ft_free(&temp);
	return (variable);
}

static char	**split_input(char *input, t_shell *shell)
{
	int		i;
	char	**array;

	i = 0;
	if (!validate_quote_number(shell->input))
	{
		shell->flag = false;
		return (NULL);
	}
	array = safe_malloc(sizeof(char *) * (word_count(input) + 1));
	while (*input)
	{
		while (*input && ft_isspace(*input))
			input++;
		if (*input && (*input == '\'' || *input == '\"'))
			array[i++] = extract_quote(&input);
		else if (*input && ft_strchr("|<>*&", *input))
			array[i++] = extract_operator(&input, shell);
		else if (*input && (*input == '$'))
			array[i++] = extract_variable(&input);
		else
			array[i++] = extract_command(&input);
	}
	array[i] = NULL;
	return (array);
}

void	parse(t_shell *shell)
{
	char	*temp;
	char	*expanded_temp;

	temp = ft_strtrim(shell->input, " ");
	shell->flag = true;
	error_quote(shell);
	expanded_temp = expand(temp, shell->env, shell->exit_status);
	ft_free(&temp);
	temp = expanded_temp;
	shell->flag = true;
	error_quote(shell);
	shell->array = split_input(temp, shell);
	if (!shell->flag)
		free_matrix(shell->array);
	if (shell->flag)
	{
		shell->token = tokenize_array(shell->array);
		identify_tokens(shell->token);
		token_sequence(shell->token);
	}
	ft_free(&temp);
}

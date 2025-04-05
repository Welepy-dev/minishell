/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:47:02 by mchingi           #+#    #+#             */
/*   Updated: 2025/04/04 15:12:51 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

char	*remove_outside_quotes(char *command)
{
	size_t	len;
	char	*unquoted_command;

	len = ft_strlen(command);
	if (len >= 2
		&& ((command[0] == '\'' && command[len - 1] == '\'')
			|| (command[0] == '"' && command[len - 1] == '"')))
	{
		unquoted_command = safe_malloc(sizeof(char) * (len - 1));
		ft_strlcpy(unquoted_command, command + 1, len - 1);
	}
	else
		unquoted_command = strdup(command);
	ft_free(&command);
	return (unquoted_command);
}

static char	*extract_command(char **input)
{
	char	*command;
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (**input && (!ft_isspace(**input) || quote)
		&& !ft_strchr("|<>«»&*", **input))
	{
		if (!quote && (**input == '\'' || **input == '"'))
			quote = **input;
		else if (quote && **input == quote)
			quote = 0;
		i++;
		(*input)++;
	}
	command = ft_strndup((*input) - i, i);
	return (remove_outside_quotes(command));
}

char	*extract_variable(char **input)
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
	free(temp);
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
		while (ft_isspace(*input) && *input)
			input++;
		if (*input == '\'' || *input == '\"')
			array[i++] = extract_quote(&input);
		else if (ft_strchr("|<>&", *input))
			array[i++] = extract_operator(&input, shell);
		else if (*input == '$')
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
	expanded_temp = expand(temp, shell->env, shell->exit_status);
	free(temp);
	temp = expanded_temp;
	shell->flag = true;
	error_quote(shell);
	shell->array = split_input(temp, shell);
	if (!shell->flag)
		free_matrix(shell->array);
	if (shell->flag)
	{
		shell->token = tokenize_array(shell->array);
		identify_tokens(shell->token, shell->path);
		token_sequence(shell->token);
	}
	ft_free(&temp);
}

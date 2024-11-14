/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_input_ext.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:52:59 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/14 14:11:21 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*fill_quote(char **input, char quote, int i)
{
	char	*quote_string;
	char	*temp;

	temp = ft_strndup((*input) - i, i);
	quote_string = safe_malloc(sizeof(char) * (i + 3));
	quote_string[0] = quote;
	ft_strncpy(quote_string + 1, temp, i);
	quote_string[i + 1] = quote;
	quote_string[i + 2] = '\0';
	free(temp);
	return (quote_string);
}

char	*extract_variable(char **input)
{
	char	*variable;
	int		i;
	char	*temp;

	i = 0;
	(*input)++;
	while (**input && (ft_isalnum(**input) || **input == '_'))
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
	printf("variable %s\n", variable);
	return (variable);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expansion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 13:20:02 by welepy            #+#    #+#             */
/*   Updated: 2025/03/29 17:40:27 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minihell.h"

static void	calculate_result_size_util(int *k, char *input,
	t_env *env, size_t *result_size)
{
	size_t	var_len;
	char	*env_value;
	char	*temp;

	var_len = 0;
	(*k)++;
	while (ft_isalnum(input[*k + var_len]) || input[*k + var_len] == '_')
		var_len++;
	temp = ft_strndup(input + *k, var_len);
	env_value = get_env_value(temp, env);
	free(temp);
	if (env_value)
		*result_size += ft_strlen(env_value);
	else
		*result_size += 0;
	*k += var_len - 1;
}

static size_t	calculate_result_size(char *input, t_env *env, int exit_status)
{
	size_t	result_size;
	int		k;

	k = -1;
	result_size = 0;
	while (input[++k])
	{
		if (input[k] == '$')
		{
			if (input[k + 1] == '?')
			{
				result_size += ft_strlen_free(ft_itoa(exit_status));
				k++;
			}
			else if (ft_isalpha(input[k + 1]) || input[k + 1] == '_')
				calculate_result_size_util(&k, input, env, &result_size);
			else
				result_size++;
		}
		else
			result_size++;
	}
	return (result_size);
}

static void	append_exit_status(char *result, size_t *j,
	int exit_status, size_t *i)
{
	char	*exit_status_str;

	exit_status_str = ft_itoa(exit_status);
	ft_strcpy(result + *j, exit_status_str);
	*j += ft_strlen(exit_status_str);
	*i += 2;
	ft_free(&exit_status_str);
}

static void	concat(t_strings strings, size_t *j,
	size_t *i, t_env *env)
{
	size_t	var_len;
	char	*env_value;
	char	*temp;

	(*i)++;
	var_len = 0;
	while (ft_isalnum(strings.s1[*i + var_len])
		|| strings.s1[*i + var_len] == '_')
		var_len++;
	temp = ft_strndup(strings.s1 + *i, var_len);
	env_value = get_env_value(temp, env);
	free(temp);
	if (env_value)
	{
		ft_strcpy(strings.s2 + *j, env_value);
		*j += ft_strlen(env_value);
	}
	*i += var_len;
}

char	*expand(char *input, t_env *env, int exit_status)
{
	char	*result;
	size_t	tab[2];
	int		flag;

	tab[0] = 0;
	tab[1] = 0;
	flag = 1;
	result = safe_malloc(calculate_result_size(input, env, exit_status) + 1);
	while (input[tab[0]])
	{
		flag *= expand_flag(input, tab[0]);
		if (input[tab[0]] == '$' && flag != -1)
		{
			if (input[tab[0] + 1] == '?')
				append_exit_status(result, &tab[1], exit_status, &tab[0]);
			else if (ft_isalpha(input[tab[0] + 1]) || input[tab[0] + 1] == '_')
				concat((t_s){.s1 = input, .s2 = result}, &tab[1], &tab[0], env);
			else
				result[tab[1]++] = input[tab[0]++];
		}
		else
			result[tab[1]++] = input[tab[0]++];
	}
	result[tab[1]] = '\0';
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:02:03 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/11 15:03:57 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <limits.h>
# include <ctype.h>
# include <stdlib.h>
#include <stddef.h>
# include <unistd.h>

int		ft_abs(int n);
int		numlen(int n);
int		ft_sqrt(int n);
int		ft_putnbr(int n);
int		tablen(int *tab);
int		ft_isdigit(int c);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isprint(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isspace(int c);
int		ft_putstr(const char *s);
int		ft_atoi(const char *str);
int		in_range(int n, int min, int max);
int		*quicksort(int *tab, unsigned int size);
int		*r_quicksort(int *tab, unsigned int size);

void	ft_putchar(char c);
void	*safe_malloc(size_t size);
int	matrix_len(char **matrix);
int	matrix_len(char **matrix);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memmove(void *dst, const void *src, size_t len);

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

double	ft_atof(const char *str);

double	ft_pow(double base, double exp);

char		**ft_split(char const *str, char c);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strscat(char *dest, const char *src);
char		*ft_strncat(char *dest, const char *src, size_t n);
char		*ft_strsncat(char *dest, const char *src, size_t n);

#endif

/*div
stpcpy
remove element from matrix
add element to matrix
shift left/right (arrays (int, char), lists, matrix)*/
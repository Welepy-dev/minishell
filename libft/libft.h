/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:02:03 by marcsilv          #+#    #+#             */
/*   Updated: 2024/11/13 10:13:43 by marcsilv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <stddef.h>
# include <limits.h>
# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <ctype.h>
# include <errno.h>
# include <stdarg.h>
# include "./lists/ft_list.h"
# include "../minishell.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_abs(int n);
int		numlen(int n);
int		ft_sqrt(int n);
int		ft_putnbr(int n);
int		tablen(int *tab);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_atoi(const char *str);
int		matrix_len(char **matrix);
int		lower(unsigned int decimalnumber);
int		ft_print_unsigned(unsigned int n);
int		ft_print_ptr(unsigned long long *ptr);
int		ft_printf(const char *my_string, ...);
int		*quicksort(int *tab, unsigned int size);
int		ft_strcmp(const char *s1, const char *s2);
int		*r_quicksort(int *tab, unsigned int size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

bool	ft_isdigit(int c);
bool	ft_isupper(int c);
bool	ft_islower(int c);
bool	ft_isprint(int c);
bool	ft_isalnum(int c);
bool	ft_isalpha(int c);

bool	ft_isascii(int c);
bool	ft_isspace(int c);
bool	in_range(int n, int min, int max);

void	*safe_malloc(size_t size);
void	free_matrix(char **matrix);
void	clean_and_exit(void *data);
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_fd(int n, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(const char *s, int fd);
void	*ft_realloc(void *ptr, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_calloc(size_t count, size_t size);
void	*ft_memchr(const void *s, int c, size_t n);
void	print_error(char *error_message, void *data);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);

double	ft_atof(const char *str);
double	ft_pow(double base, double exp);

char		*ft_itoa(int n);
char		*get_next_line(int fd);
char		*ft_strdup(const char *s);
char		*ft_strsjoin(char *s1, char *s2);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strscat(char *dest, const char *src);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_strncat(char *dest, const char *src, size_t n);
char		*ft_strsncat(char *dest, const char *src, size_t n);
char		*ft_strnstr(const char *s, const char *a, size_t n);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	**copy_matrix(char **matrix);
char	**ft_split(char const *s, char c);
char	**ft_split(char const *str, char c);
char	**add_str_matrix(char **matrix, char *str);
char	**rm_str_matrix_index(char **matrix, int index);

#endif
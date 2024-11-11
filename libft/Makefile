# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcsilv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 01:14:20 by marcsilv          #+#    #+#              #
#    Updated: 2024/05/27 14:00:57 by marcsilv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
INC_DIR = includes
OBJ_DIR = .
HEADER = libft.h

SRC_FILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_putchar_fd.c\
	    ft_isdigit.c ft_isprint.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c ft_putstr_fd.c\
            ft_memset.c ft_substr.c ft_tolower.c ft_toupper.c  ft_strtrim.c ft_putnbr_fd.c\
	    ft_strchr.c ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_putendl_fd.c ft_strcmp.c\
            ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strjoin.c ft_split.c ft_itoa.c ft_striteri.c\
	    ft_strmapi.c\
            
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_PATHS = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

BONUS_FILES = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstclear.c\
	      ft_lstdelone.c ft_lstiter.c ft_lstmap.c\

BONUS_OBJ_FILES = $(BONUS_FILES:.c=.o)
BONUS_OBJ_PATHS = $(addprefix $(OBJ_DIR)/, $(BONUS_OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJ_PATHS)
	ar rcs $(NAME) $(OBJ_PATHS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

bonus: $(OBJ_PATHS) $(BONUS_OBJ_PATHS)
	ar rcs $(NAME) $(OBJ_PATHS) $(BONUS_OBJ_PATHS)

clean:
	rm -f $(OBJ_FILES) $(BONUS_OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

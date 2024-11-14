# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 14:34:20 by welepy            #+#    #+#              #
#    Updated: 2024/11/14 17:38:20 by marcsilv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
CC		= cc
CFLAGS		= -Wall -Wextra -Werror
LRFLAGS		= -lreadline
OBJS		= $(SRCS:.c=.o)
SRCS		= ./utils/env/convert_env.c ./utils/parse_utils/utils.c ./split/split_input_ext.c ./split/split_input.c minishell.c
HEADER		= minishell.h
LIBFT		= libft  # Name of the subfolder containing the Makefile
lft		= $(LIBFT)/libft.a
OBJ_DIR 	= .


OBJ_PATHS = $(addprefix $(OBJ_DIR)/, $(OBJS))
LIBFT = ./libft/

all: $(NAME)

LIBMAKE = $(MAKE) -C $(LIBFT)

$(NAME):	$(OBJ_PATHS) 
		@echo "Compiling $(NAME)..."
		@$(MAKE) -C $(LIBFT)
		@$(CC) $(OBJ_PATHS) -L./libft -lft $(LRFLAGS) $(CFLAGS) -o $(NAME)

# Recursively invoke make in the subfolder
submake:
	$(LIBMAKE)
  
clean:
	rm -f $(OBJS)
	$(LIBMAKE) clean

fclean: clean
	rm -f $(NAME)
	$(LIBMAKE) fclean

re: fclean all

.PHONY: all clean fclean re LIBMAKE

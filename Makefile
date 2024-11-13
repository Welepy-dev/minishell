# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 14:34:20 by welepy            #+#    #+#              #
#    Updated: 2024/11/13 11:49:29 by marcsilv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = minishell
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
LRFLAGS = -lreadline
OBJS    = $(SRCS:.c=.o)
SRCS    = minishell.c
HEADER  = minishell.h
LIBFT	= libft  # Name of the subfolder containing the Makefile
lft	= $(LIBFT)/libft.a
OBJ_DIR = .


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

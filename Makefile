# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marcsilv <marcsilv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 15:16:15 by mchingi           #+#    #+#              #
#    Updated: 2025/04/02 16:14:21 by marcsilv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RLFLAG = -lreadline

RM = rm -rf

SRCS = 	./srcs/executer/executer.c \
		./srcs/executer/command_executer.c \
		./srcs/executer/pipe_executer.c \
		./srcs/executer/executer_utils.c \
		./srcs/executer/executer_utils1.c \
		./srcs/redirections.c \
		./srcs/utils/utils.c \
		./srcs/utils/utils1.c \
		./srcs/utils/utils2.c \
		./srcs/utils/utils3.c \
		./srcs/utils/utils4.c \
		./srcs/main.c \
		./srcs/signal.c \
		./srcs/here_document.c \
		./srcs/tokens/tokens.c \
		./srcs/tokens/tokens_utils.c \
		./srcs/parse/parse.c \
		./srcs/parse/expansion.c 	\
		./srcs/parse/parse_utils.c \
		./srcs/parse/parse_utils2.c \
		./srcs/parse/parse_utils3.c \
		./srcs/parse/parse_utils4.c \
		./srcs/builtins/cd.c \
		./srcs/builtins/env.c \
		./srcs/builtins/unset.c \
		./srcs/builtins/export.c \
		./srcs/builtins/pwd.c \
		./srcs/builtins/exit.c \
		./srcs/builtins/echo.c	\
		./srcs/builtins/echo_utils.c

HEADER = ./inc/minihell.h

LIBFT = ./libft

LFT = $(LIBFT)/libft.a

OBJ_DIR = objects

OBJS = $(SRCS:./srcs/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

# Ensure the object directory is created before compiling
$(OBJ_DIR):
	@echo "Creating object directories..."
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)/utils
	@mkdir -p $(OBJ_DIR)/tokens
	@mkdir -p $(OBJ_DIR)/parse
	@mkdir -p $(OBJ_DIR)/builtins
	@mkdir -p $(OBJ_DIR)/executer

# Compile source files into object files
$(OBJ_DIR)/%.o: ./srcs/%.c $(HEADER) | $(OBJ_DIR)
	@echo "Compiling $< into $@"
	$(CC) $(CFLAGS) -I ./inc -c $< -o $@

# Build the final executable

$(NAME): $(LFT) $(OBJS)
	@echo "Linking object files and libraries to create $(NAME)"
	$(CC) $(CFLAGS) $(OBJS) $(LFT) $(RLFLAG) -o $(NAME)

# Build the libft library
$(LFT):
	@echo "Building libft library..."
	@make -C $(LIBFT)

# Clean object files
clean:
	@echo "Cleaning object files..."
	$(RM) $(OBJ_DIR)
	@make -C $(LIBFT) clean

# Clean everything
fclean: clean
	@echo "Cleaning all..."
	$(RM) $(NAME)
	@make -C $(LIBFT) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re

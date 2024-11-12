# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: welepy <welepy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/23 01:14:20 by marcsilv          #+#    #+#              #
#    Updated: 2024/11/12 16:48:50 by welepy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = srcs
INC_DIR = includes
OBJ_DIR = .
HEADER = libft.h
CTYPE = ./ctype/*.c
CUSTOM = ./custom_functions/*.c
CUSTOM_ = ./custom_functions/length/*.c
MATRIX = ./custom_functions/matrix/*.c
BOOLS = ./custom_functions/bools/*.c
PRINTF = ./custom_functions/prints/*.c
LISTS = ./lists/*.c
MATH = ./math/*.c
SAFE_FUNCTIONS = ./safe_functions/*.c
STDLIB = ./stdlib/*.c
STRING = ./string/*.c

SRC_FILES = $(CTYPE) $(CUSTOM) $(PRINTF) $(LISTS) $(MATH) $(SAFE_FUNCTIONS) $(STDLIB) $(STRING) $(CUSTOM_) $(MATRIX) $(BOOLS)
            
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ_PATHS = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

all: $(NAME)

$(NAME): $(OBJ_PATHS)
	ar rcs $(NAME) $(OBJ_PATHS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(BONUS_OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

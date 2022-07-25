# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 10:52:54 by ede-alme          #+#    #+#              #
#    Updated: 2022/07/18 13:43:49 by ede-alme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Binary
NAME = push_swap

# Path
SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INCDIR = includes

# Files name
SRC_NAME = huge_rules.c \
			operations1.c \
			operations2.c \
			push_swap_utils.c \
			push_swap.c

OBJ_NAME = $(SRC_NAME:.c=.o)

# Files resource
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

# Flags
CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ) 
	$(CC) $(OBJ) -o $@

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -rf $(NAME)

re: fclean all

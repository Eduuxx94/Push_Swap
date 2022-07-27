# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ede-alme <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/18 10:52:54 by ede-alme          #+#    #+#              #
#    Updated: 2022/07/27 08:33:00 by ede-alme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC_PATH = ./srcs/
OBJ_PATH = ./objs/
INCDIR = includes

SRC_NAME = huge_rules.c \
			operations1.c \
			operations2.c \
			push_swap_utils.c \
			push_swap.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

CC = gcc -fsanitize=address
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJ) 
	$(CC) $(OBJ) -o $@

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

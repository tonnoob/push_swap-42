# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/17 02:02:18 by osousa-d          #+#    #+#              #
#    Updated: 2026/01/17 21:41:26 by otton-sousa      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	./src/main.c ./src/radix.c \
		./src/validation.c ./src/validation_utils.c \
		./src/initializers.c ./src/dispatcher.c \
		./src/moves.c ./src/moves_utils.c \
		./src/mini_sort.c ./src/mini_sort_utils.c \
		./src/add_index.c

OBJ = $(SRC:.c=.o)

INCLUDES = -Ilibftprintf/ft_printf -Ilibftprintf/libft -I.

LIBFTPRINTF_DIR = libftprintf
LIBFTPRINTF = $(LIBFTPRINTF_DIR)/libftprintf.a

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTPRINTF)
	$(CC) $(OBJ) -Llibftprintf -lftprintf -o $(NAME)

$(LIBFTPRINTF):
	make -C $(LIBFTPRINTF_DIR)
	
clean:
	rm -f $(OBJ)
	make clean -C $(LIBFTPRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTPRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: otton-sousa <otton-sousa@student.42.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/17 02:02:18 by osousa-d          #+#    #+#              #
#    Updated: 2026/02/08 21:22:57 by otton-sousa      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -Ilibs/libft -Ilibs/ft_printf -I.
DEBUG = -g

SRC_DIR = src
OBJ_DIR = obj

SRC = main.c radix.c validation.c validation_utils.c \
      initializers.c dispatcher.c moves.c moves_utils.c \
      mini_sort.c mini_sort_utils.c add_index.c

SRC := $(addprefix $(SRC_DIR)/, $(SRC))

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT = libs/libft/libft.a
PRINTF = libs/ft_printf/ft_printf.a
LIBS = $(PRINTF) $(LIBFT)

all: $(NAME)
	@echo "✅ Executável push_swap criado"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJ) $(LIBS)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(LIBFT):
	@make -C libs/libft --no-print-directory

$(PRINTF):
	@make -C libs/ft_printf --no-print-directory

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C libs/libft clean --no-print-directory
	@make -C libs/ft_printf clean --no-print-directory
	@echo "🧹 Objetos removidos."

fclean: clean
	@rm -f $(NAME)
	@make -C libs/libft fclean --no-print-directory
	@make -C libs/ft_printf fclean --no-print-directory
	@echo "🗑️  Tudo limpo!"

re: fclean all

valgrind: debug
	@echo "🔍 Verificando vazamentos"
	valgrind --leak-check=full \
			 --show-leak-kinds=all \
			 --track-origins=yes \
			 --track-fds=yes \
			 ./$(NAME) $(ARGS)
	
debug: CFLAGS += -g
debug: re

.PHONY: all clean fclean re

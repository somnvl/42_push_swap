# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: so <so@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 00:00:40 by somenvie          #+#    #+#              #
#    Updated: 2026/01/24 03:40:39 by so               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc -g
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
LIBFT = ./libft/libft.a
INCLUDE = -I./include

SRCS = srcs/main.c \
		srcs/parsing.c \
		srcs/lst_creator.c \
		srcs/lst_manager.c \
		srcs/op_swap.c \
		srcs/op_push.c \
		srcs/op_rotate.c \
		srcs/op_reverse.c \
		srcs/normalize.c \
		srcs/debug.c \

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) 
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

$(LIBFT):
	@$(MAKE) -C ./libft

$(OBJ_DIR)/%.o: ./srcs/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $^

clean:
	@$(MAKE) clean -C ./libft
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME)

re: fclean all
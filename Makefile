# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: so <so@student.42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/28 17:55:44 by so                #+#    #+#              #
#    Updated: 2026/01/28 19:54:24 by so               ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
BONUS_NAME  = checker

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
INCLUDE     = -I./includes

LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRC_DIR     = srcs
OBJ_DIR     = obj

COMMON_SRCS = $(SRC_DIR)/parsing.c \
              $(SRC_DIR)/lst_creator.c \
              $(SRC_DIR)/lst_manager.c \
              $(SRC_DIR)/op_swap.c \
              $(SRC_DIR)/op_push.c \
              $(SRC_DIR)/op_rotate.c \
              $(SRC_DIR)/op_reverse.c \
              $(SRC_DIR)/normalize.c \
              $(SRC_DIR)/debug.c \
              $(SRC_DIR)/low_sort.c \
              $(SRC_DIR)/turk_sort.c \
              $(SRC_DIR)/turk_utils.c \
              $(SRC_DIR)/turk_pick.c \
              $(SRC_DIR)/turk_apply.c

SRCS        = $(SRC_DIR)/main.c

BONUS_SRCS  = $(SRC_DIR)/checker.c \
              $(SRC_DIR)/checker_utils.c

COMMON_OBJ  = $(addprefix $(OBJ_DIR)/, $(notdir $(COMMON_SRCS:.c=.o)))
OBJ         = $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
BONUS_OBJ   = $(addprefix $(OBJ_DIR)/, $(notdir $(BONUS_SRCS:.c=.o)))

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ_DIR) $(COMMON_OBJ) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(COMMON_OBJ) $(OBJ) $(LIBFT)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(OBJ_DIR) $(COMMON_OBJ) $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $(BONUS_NAME) $(COMMON_OBJ) $(BONUS_OBJ) $(LIBFT)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c -o $@ $<

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(NAME) $(BONUS_NAME)

re: fclean all

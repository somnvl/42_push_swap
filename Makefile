# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/17 00:00:40 by somenvie          #+#    #+#              #
#    Updated: 2025/12/17 00:00:52 by somenvie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar
ARFLAGS = rcs
RM = rm -rf
INCLUDES = includes

SRCS = srcs/ft_printf.c \
		srcs/conversions.c \

OBJS = $(SRCS:.c=.o)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)
	mkdir libs/o_libft
	ar x libs/libft.a --output libs/o_libft 
	ar rcs libftprintf.a srcs/ft_printf.o srcs/conversions.o libs/o_libft/ft_putchar_fd.o libs/o_libft/ft_strlen.o
	
clean:
	$(RM) $(OBJS)
	$(RM) libs/o_libft/
 
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: somenvie <somenvie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/03 23:32:05 by somenvie          #+#    #+#              #
#    Updated: 2025/12/19 22:32:36 by somenvie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_isalpha.c \
 		ft_isdigit.c \
 		ft_isalnum.c \
 		ft_isascii.c \
 		ft_isprint.c \
		ft_iswhitespace.c \
		ft_strlen.c \
 		ft_memset.c \
 		ft_bzero.c \
 		ft_memcpy.c \
 		ft_memmove.c \
 		ft_strlcpy.c \
 		ft_strlcat.c \
 		ft_toupper.c \
 		ft_tolower.c \
 		ft_strchr.c \
 		ft_strrchr.c \
 		ft_strncmp.c \
 		ft_memchr.c \
 		ft_memcmp.c \
 		ft_strnstr.c \
 		ft_atoi.c \
 		ft_calloc.c \
 		ft_strdup.c \
 		ft_substr.c \
 		ft_strjoin.c \
 		ft_strtrim.c \
 		ft_split.c \
 		ft_itoa.c \
 		ft_strmapi.c \
 		ft_striteri.c \
 		ft_putchar_fd.c \
 		ft_putstr_fd.c \
 		ft_putendl_fd.c \
 		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstadd_back.c \
		ft_lstlast.c \
 		ft_lstdelone.c \
 		ft_lstclear.c \
 		ft_lstiter.c \
 		ft_lstmap.c \
		ft_printf.c \
		ft_printf_utils.c \
		get_next_line.c \
		get_next_line_utils.c \

CC = cc
CFLAGS = -Wall -Wextra -Werror
OBJ = $(SRCS:.c=.o)
NAME = libft.a
AR = ar
ARFLAGS = rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

bonus: $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I includes

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
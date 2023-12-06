# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rshaheen <rshaheen@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2023/11/10 21:03:40 by rshaheen      #+#    #+#                  #
#    Updated: 2023/12/06 12:19:09 by rshaheen      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_PATH = ./libft/libft.a

SRC =	ft_printf.c \
		srcs/ft_c.c \
		srcs/ft_str.c \
		srcs/ft_num.c \
		srcs/ft_unsign.c \
		srcs/ft_hex.c \
		srcs/ft_pointer.c \
		srcs/ft_convert.c \

LIBFT_SRC = libft
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft -I.

RM = rm -rf
AR = ar
COPY = cp

OBJS = $(SRC:%.c=%.o)
		

all: $(NAME)

%.o: %.c ft_printf.h
	$(CC) -c $(CFLAGS) -o $@ $<

$(LIBFT_PATH):
	make -C $(LIBFT_SRC)

$(NAME): $(LIBFT_PATH) $(OBJS)
	$(COPY) $(LIBFT_PATH) $(NAME)
	$(AR) -rcs $(NAME) $(OBJS) $(LIBFT_PATH)


clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFT_SRC) fclean

re: fclean all

.PHONY: all clean fclean re


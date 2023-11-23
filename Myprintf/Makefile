# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rshaheen <rshaheen@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2023/11/10 21:03:40 by rshaheen      #+#    #+#                  #
#    Updated: 2023/11/17 20:51:14 by rshaheen      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = ./libft/libft.a

SRC =	ft_printf.c \
		ft_c.c \
		ft_str.c \
		ft_num.c \
		ft_unsign.c \
		ft_hex.c \
		ft_pointer.c \
		ft_convert.c \

LIBFTDIR = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./libft -I./libft/includes

RM = rm -rf
AR = ar
COPY = cp

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)

$(NAME): $(LIBFT) $(OBJS)
	$(COPY) $(LIBFT) $(NAME)
	$(AR) -rcs $(NAME) $(OBJS) $(LIBFT)

%.o: %.c ft_printf.h
	$(CC) -c $(CFLAGS) -o $@ $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re


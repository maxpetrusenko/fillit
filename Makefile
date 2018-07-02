# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 16:26:20 by mpetruse          #+#    #+#              #
#    Updated: 2018/07/02 15:49:13 by mpetruse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c read.c solve.c map_op.c list.c

OBJ = main.o read.o solve.o map_op.o list.o

FLAG = -Wall -Werror -Wextra

BINS = $(patsubst %,%.o,$(SRCS))
LIBS =libft

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC) -Ilibft
	gcc $(FLAG) -o $(NAME) $(OBJ) -L./libft -lft -I libft

clean:
	rm -f $(OBJ) libft.a

fclean: clean
	rm -f $(NAME)

re:	fclean all

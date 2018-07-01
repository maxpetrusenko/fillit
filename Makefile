# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 16:26:20 by mpetruse          #+#    #+#              #
#    Updated: 2018/06/30 14:44:43 by apetrech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c read.c solve.c map_op.c list.c

OBJ = main.o read.o solve.o map_op.o list.o

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	gcc $(FLAG) -c $(SRC)
	gcc $(FLAG) -o $(NAME) $(OBJ) -L. -lft

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

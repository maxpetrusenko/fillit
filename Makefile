# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/29 16:26:20 by mpetruse          #+#    #+#              #
#    Updated: 2018/07/06 14:59:52 by mpetruse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c read.c solve.c map_op.c list.c

OBJ = main.o read.o solve.o map_op.o list.o

FLAG = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make -C libft
	gcc $(FLAG) -c $(SRC) -I libft
	gcc $(FLAG) -o $(NAME) $(OBJ) -I libft -L./libft -lft

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re:	fclean all

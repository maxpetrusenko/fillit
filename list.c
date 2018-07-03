/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 18:16:34 by mpetruse          #+#    #+#             */
/*   Updated: 2018/07/02 17:33:56 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
**frees memory from tetris
*/

t_list		*free_list(t_list *list)
{
	t_block *tetris;
	t_list	*next;

	while (list)
	{
		tetris = (t_block *)list->content;
		next = list->next;
		del_tetr(tetris);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}

/*
**empies tetrimo block of any shape(ex ####)
*/

void		del_tetr(t_block *tetr)
{
	int i;

	i = 0;
	while (i < tetr->y)
	{
		ft_memdel((void **)(&(tetr->shape[i])));
		i++;
	}
	ft_memdel((void **)(&(tetr->shape)));
	ft_memdel((void **)&tetr);
}

/*
**create new block (shape of new tetrimo) (ex #->#->#->#)
*/

t_block		*create_tetr(char **shape, int x, int y, char val)
{
	t_block	*tetr;

	tetr = ft_memalloc(sizeof(t_block));
	tetr->shape = shape;
	tetr->x = x;
	tetr->y = y;
	tetr->val = val;
	return (tetr);
}

/*
**create base square size for dots
*/

t_dot		*new_size(int x, int y)
{
	t_dot	*size;

	size = ft_memalloc(sizeof(t_dot));
	size->x = x;
	size->y = y;
	return (size);
}

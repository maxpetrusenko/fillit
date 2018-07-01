/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 15:10:46 by mpetruse          #+#    #+#             */
/*   Updated: 2018/06/30 12:40:57 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
**creates a map with a big size
*/

int		ft_solve_map(t_map *map, t_list *list)
{
	int		i;
	int		j;
	t_block	*block;

	j = 0;
	if (list == NULL)
		return (1);
	block = (t_block *)(list->content);
	while (j < map->size - block->y + 1)
	{
		i = 0;
		while (i < map->size - block->x + 1)
		{
			if (place(block, map, i, j))
			{
				if (ft_solve_map(map, list->next))
					return (1);
				else
					set_piece(block, map, new_size(i, j), '.');
			}
			i++;
		}
		j++;
	}
	return (0);
}

/*
**Check if there is enough space for the amount of
**tetri and lists and shows the square
*/

int		count_space(int i)
{
	int	size;

	size = 2;
	while (size * size < i)
		size++;
	return (size);
}

/*
**Tries to solve maps starting from the smallest possible size
*/

t_map	*mapsolve(t_list *list)
{
	t_map	*map;
	int		size;

	size = count_space(ft_lstcount(list) * 4);
	map = newmap(size);
	while (!ft_solve_map(map, list))
	{
		size++;
		del_map(map);
		map = newmap(size);
	}
	return (map);
}

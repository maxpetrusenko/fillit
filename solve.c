/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 15:10:46 by mpetruse          #+#    #+#             */
/*   Updated: 2018/07/02 17:49:40 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
** using recursion to see if block of tetrimino fits in the curr position
** in not moves it to next position
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
** Check if there is enough space on th map for mapsolve(creates a minimal
** space  for tetr)
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
** solving map starting from the smallest possible size using recursive function
** adjusts map size if needed
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

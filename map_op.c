/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 14:20:39 by mpetruse          #+#    #+#             */
/*   Updated: 2018/07/02 17:40:34 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

void	del_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}

/*
** Allocates a new map structure with specified size.
*/

t_map	*newmap(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->array = (char **)ft_memalloc(sizeof(char *) * size);
	i = 0;
	while (i < size)
	{
		map->array[i] = ft_strnew(size);
		j = 0;
		while (j < size)
		{
			map->array[i][j] = '.';
			j++;
		}
		i++;
	}
	return (map);
}

/*
**Places a tetrimino on map at specified position,
**checking if the placement is possible.
*/

int		place(t_block *tetri, t_map *map, int w, int h)
{
	int i;
	int j;

	i = 0;
	while (i < tetri->x)
	{
		j = 0;
		while (j < tetri->y)
		{
			if (tetri->shape[j][i] == '#' && map->array[h + j][w + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	set_piece(tetri, map, new_size(w, h), tetri->val);
	return (1);
}

/*
** when sees # sign changes it to the letter later
*/

void	set_piece(t_block *tetri, t_map *map, t_dot *dot, char c)
{
	int i;
	int j;

	i = 0;
	while (i < tetri->x)
	{
		j = 0;
		while (j < tetri->y)
		{
			if (tetri->shape[j][i] == '#')
				map->array[dot->y + j][dot->x + i] = c;
			j++;
		}
		i++;
	}
	ft_memdel((void **)&dot);
}

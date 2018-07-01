/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 12:12:53 by apetrech          #+#    #+#             */
/*   Updated: 2018/06/30 14:59:19 by mpetruse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

/*
**Utility function to get min-max values for get_piece.
*/

void		ft_min_max(char *str, t_dot *min, t_dot *max)
{
	int i;

	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if (i / 5 < min->y)
				min->y = i / 5;
			if (i / 5 > max->y)
				max->y = i / 5;
			if (i % 5 < min->x)
				min->x = i % 5;
			if (i % 5 > max->x)
				max->x = i % 5;
		}
		i++;
	}
}

/*
**Reads a piece from a valid chunk, allocates a structure and populates it.
*/

t_block		*ins_piece(char *str, char val)
{
	t_dot		*min;
	t_dot		*max;
	char		**place;
	int			i;
	t_block		*tetr;

	min = new_size(3, 3);
	max = new_size(0, 0);
	ft_min_max(str, min, max);
	place = ft_memalloc(sizeof(char *) * (max->y - min->y + 1));
	i = 0;
	while (i < max->y - min->y + 1)
	{
		place[i] = ft_strnew(max->x - min->x + 1);
		ft_strncpy(place[i], str + (min->x) + (i + min->y) * 5,
				max->x - min->x + 1);
		i++;
	}
	tetr = create_tetr(place, max->x - min->x + 1, max->y - min->y + 1, val);
	ft_memdel((void **)&min);
	ft_memdel((void **)&max);
	return (tetr);
}

/*
**check connections between blocks of single tetrimo
*/

int			ch_blocks(char *str)
{
	int	block;
	int i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

/*
**Checks character counts and that chunk format is valid.
*/

int			ch_count(char *str, int count)
{
	int i;
	int blocs;

	blocs = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++blocs > 4)
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
		i++;
	}
	if (count == 20 && str[20] != '\n' && str[21] != '\0')
		return (4);
	if (!ch_blocks(str))
		return (5);
	return (0);
}

/*
**increases the square size if needed
*/

t_list		*read_blocks(int fd)
{
	char	*buf;
	int		bl_count;
	int old_n;
	t_list	*list;
	t_block	*tetris;
	char	let;

	let = 'A';
	buf = ft_strnew(BASE_SIZE + 1);
	list = NULL;
	while ((bl_count = read(fd, buf, (BASE_SIZE + 1))) >= 20)
	{
		if (ch_count(buf, bl_count) || !(tetris = ins_piece(buf, let++))) 		{
			ft_memdel((void **)&buf);
			return (free_list(list));
		}
		ft_lstadd(&list, ft_lstnew(tetris, sizeof(t_block)));
		ft_memdel((void **)&tetris);
		old_n = bl_count;
	}
	ft_memdel((void **)&buf);
	if (bl_count == 0 && old_n != BASE_SIZE)
		return (free_list(list));
	ft_lstrev(&list);
	return (list);
}

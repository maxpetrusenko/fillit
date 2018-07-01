/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpetruse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 13:08:13 by mpetruse          #+#    #+#             */
/*   Updated: 2018/06/30 14:44:58 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# define BASE_SIZE 20
# include "libft.h"

typedef struct	s_dot
{
	int			x;
	int			y;
}				t_dot;

typedef struct	s_block
{
	char		**shape;
	char		val;
	int			x;
	int			y;
}				t_block;

typedef struct	s_map
{
	int			size;
	char		**array;
}				t_map;

t_list			*read_blocks(int fd);
t_list			*free_list(t_list *list);
void			del_tetr(t_block *tetr);
t_block			*create_tetr(char **shape, int x, int y, char val);
t_dot			*new_size(int x, int y);
void			ft_min_max(char *str, t_dot *min, t_dot *max);
t_block			*ins_piece(char *str, char val);
void			print_map(t_map *map);
void			del_map(t_map *map);
t_map			*newmap(int size);
int				place(t_block *tetri, t_map *map, int w, int h);
t_map			*mapsolve(t_list *list);
int				ft_solve_map(t_map *map, t_list *list);
void			set_piece(t_block *tetri, t_map *map, t_dot *dot, char c);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:09:53 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/13 12:09:57 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	get_tetri_sizes(t_tetri *tetri, char *str)
{
	int i;

	i = 0;
	tetri->height = 0;
	tetri->width = 0;
	tetri->x = 4;
	tetri->y = 4;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			tetri->x = (i % 5 < tetri->x ? i % 5 : tetri->x);
			tetri->width = (i % 5 > tetri->width ? i % 5 : tetri->width);
			tetri->y = (i / 5 < tetri->y ? i / 5 : tetri->y);
			tetri->height = (i / 5 > tetri->height ? i / 5 : tetri->height);
		}
		i++;
	}
	tetri->width -= tetri->x - 1;
	tetri->height -= tetri->y - 1;
}

t_tetri	str_to_tetri(char *str)
{
	t_tetri	tetri;
	int		i;
	int		j;

	tetri.bits = 0;
	get_tetri_sizes(&tetri, str);
	i = 0;
	while (i < tetri.height)
	{
		j = 0;
		while (j < tetri.width)
		{
			if (str[(tetri.y + i) * 5 + tetri.x + j] == '#')
				tetri.bits |= (1LL << ((i + 1) * 16 - (j + 1)));
			++j;
		}
		++i;
	}
	tetri.x = 0;
	tetri.y = 0;
	tetri.prev = NULL;
	return (tetri);
}

void	look_for_prev_same_tetri(t_tetri *tetris, int i)
{
	int j;

	j = i;
	while (--i >= 0)
	{
		if (tetris[j].bits == tetris[i].bits)
		{
			tetris[i].prev = tetris + j;
			return ;
		}
	}
}

int		read_tetris(int fd, t_tetri *tetris)
{
	char	buf[BUF_SIZE];
	int		len;
	int		total;
	int		i;

	i = 0;
	total = 0;
	while ((len = read(fd, buf, TET_SIZE)))
	{
		total += len;
		if (!check_tetri(buf, len))
			return (0);
		tetris[i] = str_to_tetri(buf);
		look_for_prev_same_tetri(tetris, i++);
	}
	return (i > TET_NB || total != (i * TET_SIZE) - 1 ? 0 : i);
}

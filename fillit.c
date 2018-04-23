/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 18:44:50 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/10 18:44:53 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		are_overlaping(uint16_t *square, t_tetri *tetri)
{
	return ((*(uint64_t *)(square + tetri->y) & (tetri->bits >> tetri->x)) > 0);
}

void	set_tetri(uint16_t *square, t_tetri *tetri)
{
	*(uint64_t *)(square + tetri->y) ^= tetri->bits >> tetri->x;
}

int		fill_square(t_tetri *tetris, int size, uint16_t *square)
{
	int i;

	if (!tetris->bits)
		return (1);
	i = (tetris->prev ? (tetris->prev->x + tetris->prev->y * size) : 0);
	tetris->y = i / size;
	while (tetris->y <= size - tetris->height)
	{
		tetris->x = (tetris->y == i / size ? i % size : 0);
		while (tetris->x <= size - tetris->width)
		{
			if (!are_overlaping(square, tetris))
			{
				set_tetri(square, tetris);
				if (fill_square(tetris + 1, size, square))
					return (1);
				set_tetri(square, tetris);
			}
			tetris->x++;
		}
		tetris->y++;
	}
	tetris->x = 0;
	tetris->y = 0;
	return (0);
}

int		get_min_size(int nb)
{
	int i;

	i = 2;
	while (i * i < nb * 4)
		i++;
	return (i);
}

int		fillit(uint16_t *square, t_tetri *tetris, int nb)
{
	int size;

	size = get_min_size(nb);
	while (!fill_square(tetris, size, square) && size <= 16)
	{
		ft_bzero(square, sizeof(uint16_t) * 16);
		++size;
	}
	return (size > 16 ? 0 : size);
}

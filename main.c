/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:37:25 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/23 14:37:29 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_tetri		tetris[TET_NB + 1];
	uint16_t	square[16];
	int			fd;
	int			nb;
	int			size;

	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			throw_exception("error");
		ft_bzero(tetris, sizeof(t_tetri) * (TET_NB + 1));
		if ((nb = read_tetris(fd, tetris)) == 0)
			throw_exception("error");
		close(fd);
		ft_bzero(square, sizeof(uint16_t) * 16);
		if ((size = fillit(square, tetris, nb)) == 0)
			throw_exception("error");
		print_square(tetris, nb, size);
	}
	else
		throw_exception("usage: ./fillit source_file");
	return (0);
}

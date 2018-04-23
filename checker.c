/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 16:16:06 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/13 16:16:08 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_linked_sharps(char *tetri, int i)
{
	int n;

	n = 0;
	if (i < TET_SIZE - 2 && tetri[i + 1] == '#')
		++n;
	if (i < TET_SIZE - 6 && tetri[i + 5] == '#')
		++n;
	return (n);
}

int		check_tetri(char *tetri, int len)
{
	int i;
	int links;
	int sharps;

	if (len < TET_SIZE - 1)
		return (0);
	i = 0;
	links = 0;
	sharps = 0;
	while (i < len)
	{
		if (i % 5 == 4 || i == 20)
		{
			if (tetri[i] != '\n')
				return (0);
		}
		else if (tetri[i] != '.' && tetri[i] != '#')
			return (0);
		if (tetri[i] == '#' && ++sharps)
			links += count_linked_sharps(tetri, i);
		++i;
	}
	return (sharps == 4 && links >= 3 && links <= 4);
}

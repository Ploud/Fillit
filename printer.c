/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 12:10:06 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/13 12:10:07 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*new_str_square(int size)
{
	char	*s;
	int		area;
	int		i;

	area = (size + 1) * (size);
	if (!(s = ft_strnew(area)))
		throw_exception("error : malloc : new_str_square -> ft_strnew");
	i = 0;
	while (i < area)
	{
		s[i] = (i % (size + 1) == size ? '\n' : '.');
		++i;
	}
	return (s);
}

void	print_square(t_tetri *t, int nb, int size)
{
	char	*s;
	int		i;
	int		j;

	t += nb - 1;
	s = new_str_square(size);
	while (nb--)
	{
		i = 0;
		while (i < t->height)
		{
			j = 0;
			while (j < t->width)
			{
				if (t->bits & (1LL << ((i + 1) * 16 - (j + 1))))
					s[(t->y + i) * (size + 1) + t->x + j] = 'A' + nb;
				++j;
			}
			++i;
		}
		--t;
	}
	ft_putstr(s);
	ft_strdel(&s);
}

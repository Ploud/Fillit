/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:20:57 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/10 19:30:50 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <stdint.h>

# include "Libft/libft.h"

# define BUF_SIZE 22
# define TET_SIZE 21
# define TET_NB 26

typedef struct		s_tetri
{
	uint64_t		bits;
	unsigned char	x;
	unsigned char	y;
	unsigned char	width;
	unsigned char	height;
	struct s_tetri	*prev;
}					t_tetri;

void				throw_exception(char *e);
int					fillit(uint16_t *square, t_tetri *tetris, int nb);
int					read_tetris(int fd, t_tetri *tetris);
int					check_tetri(char *tetri, int len);
void				print_square(t_tetri *t, int nb, int size);

#endif

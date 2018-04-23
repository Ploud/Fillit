/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exception.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/13 13:09:02 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/13 13:09:05 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	throw_exception(char *e)
{
	if (e)
		ft_putendl(e);
	exit(EXIT_FAILURE);
}

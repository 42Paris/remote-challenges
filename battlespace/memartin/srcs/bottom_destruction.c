/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bottom_destruction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 11:36:56 by memartin          #+#    #+#             */
/*   Updated: 2020/06/01 11:59:12 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/btsp.h"

static void		next_destruction(t_data *d, int x, int y)
{
	if (y != 9 && d->map[y + 1][x] != 1 && d->map[y + 1][x] != 2 && !d->s_sunk)
		bottom_destruction(d, x, y + 1);
	if (x != 9 && d->map[y][x + 1] != 1 && d->map[y][x + 1] != 2 && !d->s_sunk)
		right_destruction(d, x + 1, y);
	if (x != 0 && d->map[y][x - 1] != 1 && d->map[y][x - 1] != 2 && !d->s_sunk)
		left_destruction(d, x - 1, y);
	if (y != 0 && d->map[y - 1][x] != 1 && d->map[y - 1][x] != 2 && !d->s_sunk)
		top_destruction(d, x, y - 1);
	if (x != 9 && y != 9 && d->map[y + 1][x + 1] != 1
		&& d->map[y + 1][x + 1] != 2 && !d->s_sunk)
		bottom_right_destruction(d, x + 1, y + 1);
	if (x != 0 && y != 9 && d->map[y + 1][x - 1] != 1
		&& d->map[y + 1][x - 1] != 2 && !d->s_sunk)
		bottom_left_destruction(d, x - 1, y + 1);
	if (x != 9 && y != 0 && d->map[y - 1][x + 1] != 1
		&& d->map[y - 1][x + 1] != 2 && !d->s_sunk)
		top_right_destruction(d, x + 1, y - 1);
	if (x != 0 && y != 0 && d->map[y - 1][x - 1] != 1
		&& d->map[y - 1][x - 1] != 2 && !d->s_sunk)
		top_left_destruction(d, x - 1, y - 1);
}

static void		destruction_shield(t_data *d, int x, int y)
{
	d->map[y][x] = 3;
	get_shield(d);
	bottom_destruction(d, x, y);
}

void			bottom_destruction(t_data *d, int x, int y)
{
	d->move[0] = 'A' + y;
	d->move[1] = '0' + x;
	print_read(d);
	if (d->res == 'M')
	{
		d->map[y][x] = 1;
		return ;
	}
	else if (d->res == 'H')
	{
		d->nb_hit++;
		d->hit[d->nb_hit] = y * 10 + x;
		d->map[y][x] = 2;
		next_destruction(d, x, y);
	}
	else if (d->res == 'S')
	{
		d->hit[d->nb_hit + 1] = y * 10 + x;
		d->s_sunk = 1;
		d->nb_ship_down++;
		d->map[y][x] = 1;
	}
	else if (d->res == 'B')
		destruction_shield(d, x, y);
	clean_around(d, x, y);
}

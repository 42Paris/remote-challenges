/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 16:05:08 by memartin          #+#    #+#             */
/*   Updated: 2020/06/01 12:49:00 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/btsp.h"

static void		set_hit_point(t_data *d)
{
	int			i;

	i = 0;
	while (i <= 6)
	{
		if (d->hit[i] != 0)
			d->map[d->hit[i] / 10][d->hit[i] % 10] = 4;
		i++;
	}
	reset_hit(d);
}

void			clean_around(t_data *d, int x, int y)
{
	d->map[y][x] = 1;
	if (x != 0 && y != 0)
		d->map[y - 1][x - 1] = 1;
	if (y != 0)
		d->map[y - 1][x] = 1;
	if (x != 9 && y != 0)
		d->map[y - 1][x + 1] = 1;
	if (x != 9)
		d->map[y][x + 1] = 1;
	if (x != 9 && y != 9)
		d->map[y + 1][x + 1] = 1;
	if (y != 9)
		d->map[y + 1][x] = 1;
	if (x != 0 && y != 9)
		d->map[y + 1][x - 1] = 1;
	if (x != 0)
		d->map[y][x - 1] = 1;
}

void			pre_destruction(t_data *d, int x, int y)
{
	d->hit[0] = y * 10 + x;
	if (y != 0 && d->map[y - 1][x] != 1 && d->map[y - 1][x] != 2 && !d->s_sunk)
		top_destruction(d, x, y - 1);
	if (x != 0 && d->map[y][x - 1] != 1 && d->map[y][x - 1] != 2 && !d->s_sunk)
		left_destruction(d, x - 1, y);
	if (x != 9 && d->map[y][x + 1] != 1 && d->map[y][x + 1] != 2 && !d->s_sunk)
		right_destruction(d, x + 1, y);
	if (y != 9 && d->map[y + 1][x] != 1 && d->map[y + 1][x] != 2 && !d->s_sunk)
		bottom_destruction(d, x, y + 1);
	if (x != 9 && y != 0 && d->map[y - 1][x + 1] != 1
		&& d->map[y - 1][x + 1] != 2 && !d->s_sunk)
		top_right_destruction(d, x + 1, y - 1);
	if (x != 9 && y != 9 && d->map[y + 1][x + 1] != 1
		&& d->map[y + 1][x + 1] != 2 && !d->s_sunk)
		bottom_right_destruction(d, x + 1, y + 1);
	if (x != 0 && y != 9 && d->map[y + 1][x - 1] != 1
		&& d->map[y + 1][x - 1] != 2 && !d->s_sunk)
		bottom_left_destruction(d, x - 1, y + 1);
	if (x != 0 && y != 0 && d->map[y - 1][x - 1] != 1
		&& d->map[y - 1][x - 1] != 2 && !d->s_sunk)
		top_left_destruction(d, x - 1, y - 1);
	clean_around(d, x, y);
	set_hit_point(d);
	d->s_sunk = 0;
}

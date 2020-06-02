/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shield.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 15:17:21 by memartin          #+#    #+#             */
/*   Updated: 2020/06/01 12:46:54 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/btsp.h"

static void		set_shield_in_range(t_data *d, int x, int y)
{
	int			i;
	int			j;

	j = y - 2;
	if (j < 0)
		j = 0;
	while (j <= y + 2 && j < 10)
	{
		i = x - 2;
		if (i < 0)
			i = 0;
		while (i <= x + 2 && i < 10)
			d->shield[j][i++] = 0;
		j++;
	}
}

static void		set_shield_out_of_range(t_data *d, int x, int y)
{
	int			i;
	int			j;

	j = 0;
	d->shield[y][x] = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			if ((j >= y - 2 && j <= y + 2) && (i >= x - 2 && i <= x + 2))
				i++;
			else
			{
				d->shield[j][i] = 0;
				i++;
			}
		}
		j++;
	}
}

static void		set_shield_zone(t_data *d)
{
	int			i;
	int			j;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			if (d->map[j][i] == 1)
				d->shield[j][i] = 0;
			else if (d->map[j][i] == 2 || d->map[j][i] == 4)
				set_shield_in_range(d, i, j);
			else if (d->map[j][i] == 3)
				set_shield_out_of_range(d, i, j);
			i++;
		}
		j++;
	}
}

static void		after_res(t_data *d)
{
	char	c;

	c = d->res;
	if (c == 'M')
		d->map[d->move[0] - 'A'][d->move[1] - '0'] = 1;
	else if (c == 'H')
	{
		d->map[d->move[0] - 'A'][d->move[1] - '0'] = 2;
		pre_destruction(d, d->move[1] - '0', d->move[0] - 'A');
	}
	else if (c == 'B')
		d->map[d->move[0] - 'A'][d->move[1] - '0'] = 3;
	else if (c == 'S')
	{
		d->map[d->move[0] - 'A'][d->move[1] - '0'] = 1;
		d->b_shield = 1;
	}
}

void			get_shield(t_data *d)
{
	while (!d->b_shield)
	{
		reset_shield_grid(d);
		set_shield_zone(d);
		set_move_shield(d, get_rand(nb_possible_shield(d->shield)));
		set_suffix_move(d);
		print_read(d);
		after_res(d);
	}
}

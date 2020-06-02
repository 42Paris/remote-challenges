/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 12:06:53 by memartin          #+#    #+#             */
/*   Updated: 2020/06/01 10:33:26 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/btsp.h"

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
	{
		d->map[d->move[0] - 'A'][d->move[1] - '0'] = 3;
		get_shield(d);
	}
	else if (c == 'S')
	{
		d->map[d->move[0] - 'A'][d->move[1] - '0'] = 1;
		d->b_shield = 1;
	}
}

void			start_chase(t_data *d)
{
	int		nb_hit;

	nb_hit = 0;
	while (nb_hit <= 200 && d->nb_ship_down < 5)
	{
		set_highest_prob(d);
		set_move(d, get_rand(d->nb_prob), d->highest_prob);
		set_suffix_move(d);
		print_read(d);
		after_res(d);
		set_weight(d);
		nb_hit++;
	}
}

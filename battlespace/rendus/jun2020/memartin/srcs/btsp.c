/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btsp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 12:43:57 by memartin          #+#    #+#             */
/*   Updated: 2020/06/01 12:54:22 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/btsp.h"

static void		init_data(t_data *d)
{
	d->map = init_grid(0);
	d->weight = init_grid(0);
	d->shield = init_grid(1);
	reset_hit(d);
	d->b_shield = 0;
	d->s_sunk = 0;
	d->move[0] = 'A';
	d->move[1] = '0';
	d->move[2] = '\n';
	d->move[3] = '\0';
	d->nb_ship_down = 0;
	d->res = 0;
}

int				main(void)
{
	t_data	d;

	init_data(&d);
	start_chase(&d);
	return (0);
}

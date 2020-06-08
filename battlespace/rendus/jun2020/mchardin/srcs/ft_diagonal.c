/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diagonal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 17:03:28 by mchardin          #+#    #+#             */
/*   Updated: 2020/06/02 22:39:38 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

t_idx
	xy_bottom(t_btsp *btsp, t_ship *ship, t_box box, int skip)
{
	t_idx		tmp;
	t_idx		next;

	tmp = ret_around(ship->line, BO, ship->dir);
	while (is_box(*btsp, tmp.i, tmp.j, HIT))
		tmp = ret_around(tmp, BO, ship->dir);
	next = ret_around(tmp, LE, ship->dir);
	if (is_box(*btsp, next.i, next.j, box) && skip < 5)
		return (ret_around(tmp, RI, ship->dir));
	next = ret_around(tmp, RI, ship->dir);
	if (is_box(*btsp, next.i, next.j, box))
		return (ret_around(tmp, LE, ship->dir));
	return (ship->line);
}

t_idx
	xy_pattern(t_btsp *btsp, t_ship *ship, t_box box, int skip)
{
	t_idx		next;

	next = ret_around(ship->line, BO_LE, ship->dir);
	if (is_box(*btsp, next.i, next.j, box) && skip < 1)
		return (ret_around(ship->line, BO_RI, ship->dir));
	next = ret_around(ship->line, BO_RI, ship->dir);
	if (is_box(*btsp, next.i, next.j, box) && skip < 2)
		return (ret_around(ship->line, BO_LE, ship->dir));
	next = ret_around(ship->line, TO_LE, ship->dir);
	if (is_box(*btsp, next.i, next.j, box) && skip < 3)
		return (ret_around(ship->line, TO_RI, ship->dir));
	next = ret_around(ship->line, TO_RI, ship->dir);
	if (is_box(*btsp, next.i, next.j, box) && skip < 4)
		return (ret_around(ship->line, TO_LE, ship->dir));
	return (xy_bottom(btsp, ship, box, skip));
}

t_idx
	square_pattern(t_btsp *btsp, t_ship *ship, t_box box, int skip)
{
	t_idx		next;

	next = ret_around(ship->line, LE, ship->dir);
	if (is_box(*btsp, next.i, next.j, box) && skip < 1)
		return (ret_around(ship->line, BO_LE, ship->dir));
	next = ret_around(ship->line, BO_LE, ship->dir);
	if (is_box(*btsp, next.i, next.j, box) && skip < 2)
		return (ret_around(ship->line, LE, ship->dir));
	next = ret_around(ship->line, BO_RI, ship->dir);
	if (is_box(*btsp, next.i, next.j, box) && skip < 3)
		return (ret_around(ship->line, RI, ship->dir));
	next = ret_around(ship->line, RI, ship->dir);
	if (is_box(*btsp, next.i, next.j, box) && skip < 4)
		return (ret_around(ship->line, BO_RI, ship->dir));
	return (ship->line);
}

t_idx
	diag_pattern(t_btsp *btsp, t_ship *ship, t_box box, int skip)
{
	t_idx		next;
	t_idx		tmp;

	next = ret_around(ship->line, BO_LE, ship->dir);
	tmp = next;
	if (is_box(*btsp, next.i, next.j, box) && skip < 1)
		return (ret_around(ship->line, BO_RI, ship->dir));
	next = ret_around(ship->line, BO_RI, ship->dir);
	if (is_box(*btsp, next.i, next.j, HIT))
		tmp = next;
	next = ret_around(ship->line, TO_RI, ship->dir);
	if (is_box(*btsp, next.i, next.j, HIT))
		tmp = next;
	if (is_box(*btsp, next.i, next.j, box) && skip < 2)
		return (ret_around(ship->line, BO_LE, ship->dir));
	if (skip < 3)
		return (ret_around(ship->line, TO_RI, ship->dir));
	if (skip < 4)
		return (ret_around(ship->line, TO_LE, ship->dir));
	return (tmp);
}

t_idx
	triple_pattern(t_btsp *btsp, t_ship *ship, t_box box, int skip)
{
	t_idx		next;
	t_idx		tmp;
	int			side;

	next = ret_around(ship->line, BO_LE, ship->dir);
	tmp = next;
	side = 0;
	if (is_box(*btsp, next.i, next.j, box) && skip < 1)
		return (ret_around(ship->line, BO_RI, ship->dir));
	next = ret_around(ship->line, BO_RI, ship->dir);
	if (is_box(*btsp, next.i, next.j, HIT))
	{
		tmp = next;
		side = 1;
	}
	if (is_box(*btsp, next.i, next.j, box) && skip < 2)
		return (ret_around(ship->line, BO_LE, ship->dir));
	return (ret_around(tmp, side ? RI : LE, ship->dir));
}

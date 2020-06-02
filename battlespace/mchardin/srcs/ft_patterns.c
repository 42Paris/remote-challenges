/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_patterns.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 20:27:00 by mchardin          #+#    #+#             */
/*   Updated: 2020/06/02 23:07:02 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

t_idx
	ret_around(t_idx box, t_around around, t_line dir)
{
	if (around == TO)
		return (add_to_idx(box, -1 * !dir, -1 * dir));
	if (around == BO)
		return (add_to_idx(box, !dir, dir));
	if (around == LE)
		return (add_to_idx(box, -1 * dir, -1 * !dir));
	if (around == RI)
		return (add_to_idx(box, dir, !dir));
	if (around == TO_LE)
		return (add_to_idx(box, -1, -1));
	if (around == TO_RI)
		return (add_to_idx(box, dir - !dir, !dir - dir));
	if (around == BO_RI)
		return (add_to_idx(box, 1, 1));
	if (around == BO_LE)
		return (add_to_idx(box, !dir - dir, dir - !dir));
	return (box);
}

int
	around_ship(t_btsp *btsp)
{
	t_idx	next;
	int		skip;
	int		i;

	skip = 0;
	while (skip < 8)
	{
		i = 0;
		while (btsp->ship[i].i >= 0)
		{
			next = step_to(btsp, btsp->ship[i], UNKNOWN, skip);
			if (next_solve(btsp, next))
				return (0);
			i++;
		}
		skip++;
	}
	btsp->last_hit.i = -1;
	return (1);
}

int
	try_pattern(t_btsp *btsp, t_ship *ship,
	t_idx (*pattern_ft)(t_btsp *, t_ship *, t_box, int))
{
	t_idx		next;
	int			skip;
	t_box		box;

	if (ship->size > ship->len)
		box = HIT;
	else
		box = UNKNOWN;
	skip = 0;
	while (skip < 8)
	{
		next = pattern_ft(btsp, ship, box, skip);
		if (next_solve(btsp, next))
		{
			if ((skip > 1 && pattern_ft == xy_pattern)
			|| pattern_ft == triple_pattern || pattern_ft == diag_pattern)
				btsp->alien = 1;
			return (0);
		}
		skip++;
	}
	if (pattern_ft == diag_pattern)
		ship->line = next;
	return (1);
}

int
	known_patterns(t_btsp *btsp, t_ship *ship)
{
	if (ship->len == 2 && is_box(*btsp, ship->line.i + !ship->dir,
	ship->line.j + ship->dir, HIT))
		return (try_pattern(btsp, ship, square_pattern));
	else if (ship->len == 2)
		return (try_pattern(btsp, ship, triple_pattern));
	else if (ship->len == 3)
		return (try_pattern(btsp, ship, xy_pattern));
	else if (ship->len == 1 && ship->size == 2
	&& try_pattern(btsp, ship, diag_pattern))
		return (try_pattern(btsp, ship, diag_pattern));
	return (1);
}

int
	try_patterns(t_btsp *btsp)
{
	t_ship		ship;

	ft_bzero(&ship, sizeof(ship));
	ship.line = find_line(btsp->ship, &ship.dir, &ship.len, &ship.size);
	if (fill_line(btsp, ship.dir, ship.line)
	&& (ship.size < 2 || known_patterns(btsp, &ship)))
		around_ship(btsp);
	return (1);
}

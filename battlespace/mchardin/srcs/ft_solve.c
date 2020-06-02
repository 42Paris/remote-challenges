/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/31 23:17:10 by mchardin          #+#    #+#             */
/*   Updated: 2020/06/02 23:03:09 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

int
	check_later(t_btsp btsp, int i, int j)
{
	t_idx		inc;
	t_idx		end;
	int			ret;

	inc.i = i;
	inc.j = j;
	if (btsp.found_shield || !count_around(btsp, inc, BLOCKED))
		return (0);
	ret = 0;
	inc.i = i - 2 < 0 ? 0 : i - 2;
	end.i = i + 2 > 9 ? 9 : i + 2;
	end.j = j + 2 > 9 ? 9 : j + 2;
	while (inc.i <= end.i)
	{
		inc.j = j - 2 < 0 ? 0 : j - 2;
		while (inc.j <= end.j)
		{
			if (btsp.map[inc.i][inc.j] == HIT || btsp.map[inc.i][inc.j] == SUNK
			|| btsp.map[inc.i][inc.j] == MINE)
				ret++;
			inc.j++;
		}
		inc.i++;
	}
	return (ret);
}

int
	blocked_ship(t_btsp *btsp)
{
	t_idx		tmp;
	int			count;
	int			i;

	count = 0;
	i = 0;
	ft_memset(btsp->ship, -1, sizeof(btsp->ship));
	ft_bzero(&tmp, sizeof(t_idx));
	while (tmp.i >= 0)
	{
		tmp = find_box(*btsp, HIT_TMP);
		if (tmp.i >= 0)
		{
			btsp->map[tmp.i][tmp.j] = HIT;
			btsp->ship[i] = tmp;
			i++;
			if (count_around(*btsp, tmp, BLOCKED))
				count = 1;
		}
	}
	return (count);
}

int
	search_around(t_btsp *btsp)
{
	if (is_mine(btsp, btsp->ship[0]))
		btsp->map[btsp->ship[0].i][btsp->ship[0].j] = MINE;
	else if (!try_patterns(btsp))
		return (0);
	return (1);
}

int
	solve_ship(t_btsp *btsp, t_idx idx)
{
	btsp->last_hit = idx;
	if (ship_has_sunk(btsp, idx))
		return (1);
	if (blocked_ship(btsp))
		return (1);
	if (!(search_around(btsp)))
		return (0);
	return (1);
}

int
	ft_solve(t_btsp *btsp, t_idx idx, t_box box)
{
	if (box == SUNK)
		return (solve_sunk(btsp, idx));
	else if (box == HIT)
		return (solve_ship(btsp, idx));
	else if (box == EMPTY && btsp->last_hit.i >= 0)
		return (solve_ship(btsp, btsp->last_hit));
	return (0);
}

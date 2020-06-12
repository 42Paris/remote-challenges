/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sunk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 10:45:27 by mchardin          #+#    #+#             */
/*   Updated: 2020/06/02 23:02:07 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

int
	ship_has_sunk(t_btsp *btsp, t_idx idx)
{
	t_idx	step;

	if (count_around(*btsp, idx, SUNK))
	{
		step = step_to(btsp, idx, SUNK, 0);
		return (sunken_ship(btsp, step.i, step.j));
	}
	btsp->map[idx.i][idx.j] = HIT_TMP;
	while (count_around(*btsp, idx, HIT))
	{
		step = step_to(btsp, idx, HIT, 0);
		btsp->map[step.i][step.j] = HIT_TMP;
		if (ship_has_sunk(btsp, step))
			return (1);
	}
	return (0);
}

int
	solve_sunk(t_btsp *btsp, t_idx idx)
{
	if (!btsp->found_shield && !count_around(*btsp, idx, HIT))
	{
		btsp->found_shield = 1;
		btsp->map[idx.i][idx.j] = SHIELD;
		fill_all(btsp, BLOCKED, 0, 0);
		fill_all(btsp, BLOCKED, 1, 0);
		while (idx.i >= 0)
		{
			idx = find_box(*btsp, HIT);
			if (is_in_map(idx.i, idx.j))
				ft_solve(btsp, idx, HIT);
		}
	}
	else if (count_around(*btsp, idx, HIT))
	{
		ft_memset(&btsp->last_hit, -1, sizeof(t_idx));
		return (sunken_ship(btsp, idx.i, idx.j));
	}
	return (1);
}

void
	box_replace(t_btsp *btsp, int i, int j)
{
	if (!is_in_map(i, j))
		return ;
	else if (btsp->map[i][j] == UNKNOWN)
		btsp->map[i][j] = PROB_EMPTY;
	else if (btsp->map[i][j] == HIT || btsp->map[i][j] == HIT_TMP)
	{
		btsp->map[i][j] = SUNK;
		sunken_ship(btsp, i, j);
	}
}

int
	sunken_ship(t_btsp *btsp, int i, int j)
{
	box_replace(btsp, i - 1, j);
	box_replace(btsp, i, j - 1);
	box_replace(btsp, i + 1, j);
	box_replace(btsp, i, j + 1);
	box_replace(btsp, i - 1, j - 1);
	box_replace(btsp, i - 1, j + 1);
	box_replace(btsp, i + 1, j + 1);
	box_replace(btsp, i + 1, j - 1);
	return (1);
}

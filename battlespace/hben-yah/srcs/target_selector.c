/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_selector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:23:10 by hben-yah          #+#    #+#             */
/*   Updated: 2020/06/02 18:49:10 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

void	select_target_coord(t_btsp *btsp)
{
	if (btsp->shield == 0 && look_for_blocked_coordinates(btsp))
		return ;
	if (btsp->strategy == RANDOM_ATTACK)
		select_random_coordinates(btsp);
	else
		select_best_coordinates(btsp);
}

int		look_for_blocked_coordinates(t_btsp *btsp)
{
	int		i;
	int		j;

	i = 1;
	while (i < 11)
	{
		j = 1;
		while (j < 11)
		{
			if (btsp->map[i][j] == BLOCKED)
			{
				btsp->target_coord.y = i;
				btsp->target_coord.x = j;
				return (1);
			}
			++j;
		}
		++i;
	}
	return (0);
}

void	select_best_coordinates(t_btsp *btsp)
{
	int		i;
	int		j;
	int		max;

	i = 0;
	max = 0;
	while (i < 12)
	{
		j = 0;
		while (j < 12)
		{
			if (max < btsp->heat[i][j])
			{
				max = btsp->heat[i][j];
				btsp->target_coord.y = i;
				btsp->target_coord.x = j;
			}
			++j;
		}
		++i;
	}
	if (max == 0)
		btsp->strategy = RANDOM_ATTACK;
}

void	select_random_coordinates(t_btsp *btsp)
{
	int val;
	int y;
	int x;

	while (42)
	{
		val = rand() % 100;
		y = (val / 10) + 1;
		x = (val % 10) + 1;
		if (btsp->map[y][x] == UNKNOW)
		{
			btsp->target_coord.y = y;
			btsp->target_coord.x = x;
			return ;
		}
	}
}

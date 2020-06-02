/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship_heat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:18:17 by hben-yah          #+#    #+#             */
/*   Updated: 2020/06/02 18:45:16 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

void	generate_ship_heat_map(t_btsp *btsp)
{
	int		i;
	t_ship cur;

	i = 0;
	while (i < 15)
	{
		ft_memcpy(&cur, (void *)&(g_ships[i]), sizeof(t_ship));
		compute_ships_heat_map(btsp, &cur);
		rotate_ship(&cur);
		compute_ships_heat_map(btsp, &cur);
		rotate_ship(&cur);
		compute_ships_heat_map(btsp, &cur);
		rotate_ship(&cur);
		compute_ships_heat_map(btsp, &cur);
		++i;
	}
}

void	compute_ships_heat_map(t_btsp *btsp, t_ship *ship)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < 13 - ship->height)
	{
		j = 0;
		while (j < 13 - ship->width)
		{
			if ((k = is_ship_compatible(btsp, ship, i, j)))
			{
				btsp->last_compared_size = k;
				fill_ship_heat_map(btsp, ship, i, j);
			}
			++j;
		}
		++i;
	}
}

int		is_ship_compatible(t_btsp *btsp, t_ship *ship, int y, int x)
{
	int		i;
	int		j;
	int		core;
	int		attachment;

	core = 0;
	attachment = 0;
	i = -1;
	while (++i < ship->height)
	{
		j = -1;
		while (++j < ship->width)
		{
			if (ship->model[i][j] == 1)
			{
				if (btsp->map[y + i][x + j] == MISS)
					return (0);
				core += is_hit_or_blocked(btsp, y + i, x + j);
			}
			else if (ship->model[i][j] == 2
				&& (attachment += is_hit_or_blocked(btsp, y + i, x + j)) > 1)
					return (0);
		}
	}
	return (core + attachment);
}

int			is_hit_or_blocked(t_btsp *btsp, int y, int x)
{
	return (btsp->map[y][x] == HIT
				|| (btsp->map[y][x] == BLOCKED && btsp->shield == 0));
}

void		fill_ship_heat_map(t_btsp *btsp, t_ship *ship, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	while (i < ship->height)
	{
		j = 0;
		while (j < ship->width)
		{
			if (btsp->map[y + i][x + j] == UNKNOW
				|| btsp->map[y + i][x + j] == BLOCKED)
			{
				if (ship->model[i][j] == 1)
					btsp->heat[y + i][x + j] += btsp->last_compared_size
						+ btsp->conc_army[ship->army] - btsp->conc_ship[ship->id];
				else if (ship->model[i][j] == 2)
					btsp->heat[y + i][x + j] += (btsp->last_compared_size
						+ btsp->conc_army[ship->army]) * (1 - btsp->attachment);
			}
			++j;
		}
		++i;
	}
}

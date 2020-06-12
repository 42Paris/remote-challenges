/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 13:30:00 by hben-yah          #+#    #+#             */
/*   Updated: 2020/06/02 18:45:20 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

void	analyse_sunken_ship(t_btsp *btsp)
{
	int		i;
	int		j;
	int		k;
	t_ship	cur;

	i = 0;
	while (i < 15)
	{
		ft_memcpy(&cur, (void *)&(g_ships[i]), sizeof(t_ship));
		j = 0;
		while (j < 4)
		{
			if (j > 0)
				rotate_ship(&cur);
			if ((k = compare_sunken_ship_to_database(btsp, &cur)))
			{
				btsp->conc_ship[i] += 1;
				btsp->conc_army[g_ships[i].army] += 1;
				btsp->attachment = (k == 2);
				break ;
			}
			++j;
		}
		++i;
	}
}

int		compare_sunken_ship_to_database(t_btsp *btsp, t_ship *ship)
{
	int		i;

	if ((i = is_ship_concording(btsp, ship,
		btsp->last_sunken_ship_y, btsp->last_sunken_ship_x))
		|| (i = is_ship_concording(btsp, ship,
			btsp->last_sunken_ship_y - 1, btsp->last_sunken_ship_x - 1)))
		return (i);
	return (0);
}

int		is_ship_concording(t_btsp *btsp, t_ship *ship, int y, int x)
{
	int		i;
	int		j;
	int		attachment;

	attachment = 0;
	i = 0;
	while (i < ship->height)
	{
		j = 0;
		while (j < ship->width)
		{
			if (ship->model[i][j] == 1 && btsp->map[y + i][x + j] != SUNK)
				return (0);
			else if (ship->model[i][j] == 2 && btsp->map[y + i][x + j] == SUNK)
				attachment += 1;
			if (attachment > 1)
				return (0);
			++j;
		}
		++i;
	}
	return (attachment + 1);
}

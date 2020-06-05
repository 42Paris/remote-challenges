/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assessor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:22:26 by hben-yah          #+#    #+#             */
/*   Updated: 2020/06/02 18:48:04 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

void	assess_outcome(t_btsp *btsp)
{
	char	buff[1024];
	short	c;
	short	i;

	i = 0;
	while (i < 1024 && (c = ft_getc()) >= 0 && c != '\n')
		buff[i++] = c;
	buff[i] = 0;
	if (buff[0] == 'H')
	{
		btsp->map[btsp->target_coord.y][btsp->target_coord.x] = HIT;
		if (btsp->shield == 0)
			btsp->strategy = SHIP_ATTACK;
	}
	else if (buff[0] == 'S')
		sunk_ship(btsp);
	else if (buff[0] == 'B')
	{
		btsp->map[btsp->target_coord.y][btsp->target_coord.x] = BLOCKED;
		btsp->shield = 1;
		btsp->strategy = SHIELD_GEN_TRACKING;
	}
	else
		btsp->map[btsp->target_coord.y][btsp->target_coord.x] = MISS;
}

void	sunk_ship(t_btsp *btsp)
{
	btsp->map[btsp->target_coord.y][btsp->target_coord.x] = HIT;
	if (!is_sunken_element_shield_generator(btsp,
		btsp->target_coord.y, btsp->target_coord.x))
	{
		btsp->last_sunken_ship_size = 0;
		btsp->last_sunken_ship_y = 11;
		btsp->last_sunken_ship_x = 11;
		clear_sunked_ship(btsp,
			btsp->target_coord.y, btsp->target_coord.x);
		analyse_sunken_ship(btsp);
		btsp->strategy = RANDOM_ATTACK;
	}
	else
	{
		btsp->map[btsp->target_coord.y][btsp->target_coord.x] = MISS;
		btsp->shield = 0;
		btsp->strategy = SHIP_ATTACK;
	}
}

void	clear_sunked_ship(t_btsp *btsp, int y, int x)
{
	if (y >= 0 && x >= 0 && y < 12 && x < 12)
	{
		if (btsp->map[y][x] == HIT)
		{
			btsp->map[y][x] = SUNK;
			++btsp->last_sunken_ship_size;
			if (y < btsp->last_sunken_ship_y)
				btsp->last_sunken_ship_y = y;
			if (x < btsp->last_sunken_ship_x)
				btsp->last_sunken_ship_x = x;
			clear_sunked_ship(btsp, y - 1, x - 1);
			clear_sunked_ship(btsp, y - 1, x);
			clear_sunked_ship(btsp, y - 1, x + 1);
			clear_sunked_ship(btsp, y, x - 1);
			clear_sunked_ship(btsp, y, x + 1);
			clear_sunked_ship(btsp, y + 1, x - 1);
			clear_sunked_ship(btsp, y + 1, x);
			clear_sunked_ship(btsp, y + 1, x + 1);
		}
		else if (btsp->map[y][x] == UNKNOW)
			btsp->map[y][x] = MISS;
	}
}

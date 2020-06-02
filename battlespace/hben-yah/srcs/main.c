/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 08:09:19 by hben-yah          #+#    #+#             */
/*   Updated: 2020/06/02 18:48:16 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

void	generate_heat_map(t_btsp *btsp)
{
	ft_bzero(btsp->heat, sizeof(btsp->heat));
	if (btsp->strategy == SHIELD_GEN_TRACKING)
		generate_shield_heat_map(btsp);
	else if (btsp->strategy == SHIP_ATTACK)
		generate_ship_heat_map(btsp);
}

void	init_btsp(t_btsp *btsp)
{
	ft_bzero(btsp, sizeof(t_btsp));
	btsp->target_coord.x = 5;
	btsp->target_coord.y = 5;
	btsp->shield = 0;
	btsp->strategy = RANDOM_ATTACK;
	init_map(btsp);
}

void	init_map(t_btsp *btsp)
{
	int i;

	i = 0;
	while (i < 12)
	{
		btsp->map[0][i] = MISS;
		btsp->map[i][0] = MISS;
		btsp->map[11][i] = MISS;
		btsp->map[i][11] = MISS;
		++i;
	}
}

int		main(void)
{
	t_btsp			btsp;
	struct timeval	tv;

	gettimeofday(&tv,NULL);
	srand(1000000 * tv.tv_sec + tv.tv_usec);
	init_btsp(&btsp);
	while (++btsp.turn)
	{
		generate_heat_map(&btsp);
		select_target_coord(&btsp);
		launch_attack(&btsp);
		assess_outcome(&btsp);
	}
	return (0);
}

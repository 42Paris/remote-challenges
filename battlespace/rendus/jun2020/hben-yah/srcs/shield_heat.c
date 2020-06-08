/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shield_heat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:32:02 by hben-yah          #+#    #+#             */
/*   Updated: 2020/06/02 18:45:17 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

void	generate_shield_heat_map(t_btsp *btsp)
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
				fill_shield_heat_map(btsp, 1, i - 2, j - 2);
			else if (btsp->map[i][j] == HIT || btsp->map[i][j] == SUNK)
				fill_shield_heat_map(btsp, -10, i - 2, j - 2);
			++j;
		}
		++i;
	}
}

void	fill_shield_heat_map(t_btsp *btsp, int val, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 5)
		{
			if (y + i >= 0 && x + j >= 0 && y + i <= 11 && x + j <= 11
				&& btsp->map[y + i][x + j] == UNKNOW)
				btsp->heat[y + i][x + j] += val;
			++j;
		}
		++i;
	}
}

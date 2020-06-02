/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:21:21 by hben-yah          #+#    #+#             */
/*   Updated: 2020/06/02 18:45:19 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

void	rotate_ship(t_ship *ship)
{
	int		grid[10][10];
	int		i;
	int		j;

	i = 0;
	ft_bzero(grid, sizeof(grid));
	while (i < ship->height)
	{
		j = 0;
		while (j < ship->width)
		{
			grid[j][ship->height - i - 1] = ship->model[i][j];
			++j;
		}
		++i;
	}
	ship->height = j;
	ship->width = i;
	ft_memcpy(ship->model, grid, sizeof(grid));
}

int		is_sunken_element_shield_generator(t_btsp *btsp, int y, int x)
{
	if (y > 0 && x > 0 && btsp->map[y - 1][x - 1] == HIT)
		return (0);		
	if (y > 0 && btsp->map[y - 1][x] == HIT)
		return (0);		
	if (y > 0 && x < 12 && btsp->map[y - 1][x + 1] == HIT)
		return (0);		
	if (x > 0 && btsp->map[y][x - 1] == HIT)
		return (0);		
	if (x < 12 && btsp->map[y][x + 1] == HIT)
		return (0);		
	if (y < 12 && x > 0 && btsp->map[y + 1][x - 1] == HIT)
		return (0);		
	if (y < 12 && btsp->map[y + 1][x] == HIT)
		return (0);		
	if (y < 12 && x < 12 && btsp->map[y + 1][x + 1] == HIT)
		return (0);
	return (1);
}

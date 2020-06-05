/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shield.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 20:15:02 by cclaude           #+#    #+#             */
/*   Updated: 2020/06/02 10:49:55 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

int		spot_shield(char map[10][10], int i, int j)
{
	int	x;
	int	y;

	x = 0;
	while (x < 10)
	{
		y = 0;
		while (y < 10)
		{
			if (ft_abs(x - i) < 3 && ft_abs(y - j) < 3)
			{
				if (check_spot("xo", map, x, y))
					return (0);
			}
			else
			{
				if (check_spot("b", map, x, y))
					return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

int		possible_shields(char map[10][10])
{
	int	n;
	int	i;
	int	j;

	n = 0;
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (map[i][j] == '.')
				n += spot_shield(map, i, j);
			j++;
		}
		i++;
	}
	return (n);
}

void	target_shield(char map[10][10], int pdf[10][10])
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (spot_shield(map, i, j))
				pdf[i][j] += 50;
			j++;
		}
		i++;
	}
}

int		got_shield(char map[10][10], int i, int j)
{
	if (check_spot("x", map, i, j - 1))
		return (0);
	if (check_spot("x", map, i, j + 1))
		return (0);
	if (check_spot("x", map, i - 1, j))
		return (0);
	if (check_spot("x", map, i + 1, j))
		return (0);
	if (check_spot("x", map, i - 1, j - 1))
		return (0);
	if (check_spot("x", map, i - 1, j + 1))
		return (0);
	if (check_spot("x", map, i + 1, j - 1))
		return (0);
	if (check_spot("x", map, i + 1, j + 1))
		return (0);
	map[i][j] = ' ';
	return (1);
}

void	clear_blocked(char map[10][10])
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (map[i][j] == 'b')
			{
				ret = shoot(i, j);
				if (ret == BLOCKED)
					return ;
				else if (ret == SUNK)
					mark_sunk(map, i, j);
				else
					sink_boat(map, i, j);
			}
			j++;
		}
		i++;
	}
}

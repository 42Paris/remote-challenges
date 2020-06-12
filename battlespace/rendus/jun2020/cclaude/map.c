/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 20:19:42 by cclaude           #+#    #+#             */
/*   Updated: 2020/06/02 10:49:55 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

int		orientation_spot(char map[10][10], int i, int j)
{
	int	or;

	or = 0;
	if (check_spot("box", map, i, j - 1))
		or++;
	if (check_spot("box", map, i, j + 1))
		or++;
	if (check_spot("box", map, i - 1, j))
		or++;
	if (check_spot("box", map, i + 1, j))
		or++;
	if (check_spot("box", map, i - 1, j - 1))
		or--;
	if (check_spot("box", map, i - 1, j + 1))
		or--;
	if (check_spot("box", map, i + 1, j - 1))
		or--;
	if (check_spot("box", map, i + 1, j + 1))
		or--;
	return (or);
}

int		orientation(char map[10][10])
{
	int	i;
	int	j;
	int	or;

	or = 0;
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (check_spot("box", map, i, j))
				or += orientation_spot(map, i, j);
			j++;
		}
		i++;
	}
	return (or);
}

void	fill_map(char map[10][10])
{
	int		i;
	int		j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
			map[i][j++] = '.';
		i++;
	}
}

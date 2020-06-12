/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btsp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 19:51:57 by cclaude           #+#    #+#             */
/*   Updated: 2020/06/02 12:18:17 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

int		shoot(int i, int j)
{
	int		idx;
	char	in[10];
	char	out[4];

	out[0] = 65 + i;
	out[1] = 48 + j;
	out[2] = '\n';
	out[3] = '\0';
	write(1, &out, 3);
	read(0, &in, 10);
	idx = 0;
	while (in[idx] != '\n')
		idx++;
	in[idx] = '\0';
	if (ft_strcmp(in, "BLOCKED") == 0)
		return (BLOCKED);
	else if (ft_strcmp(in, "SUNK") == 0)
		return (SUNK);
	else if (ft_strcmp(in, "HIT") == 0)
		return (HIT);
	else
		return (MISS);
}

void	react(char map[10][10], int ij, int hit, int *shield)
{
	int	i;
	int	j;

	i = ij / 10;
	j = ij % 10;
	if (hit == BLOCKED)
		map[i][j] = 'b';
	else if (hit == SUNK)
	{
		if (got_shield(map, i, j))
		{
			*shield = 0;
			clear_blocked(map);
		}
		else
			mark_sunk(map, i, j);
	}
	else if (hit == HIT)
		sink_boat(map, i, j);
	else
		map[i][j] = ' ';
}

int		main(void)
{
	char	map[10][10];
	int		pdf[10][10];
	int		i;
	int		j;
	int		shield;

	shield = 1;
	fill_map(map);
	while (1)
	{
		map_coeff(map, pdf);
		if (shield && possible_shields(map) < 14)
			target_shield(map, pdf);
		find_target(map, pdf, &i, &j);
		if (i == 10 || j == 10)
			return (0);
		react(map, 10 * i + j, shoot(i, j), &shield);
	}
	return (0);
}

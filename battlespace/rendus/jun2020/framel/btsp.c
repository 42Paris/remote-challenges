/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btsp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: framel <framel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 13:17:09 by framel            #+#    #+#             */
/*   Updated: 2020/05/30 13:51:17 by framel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#define COL 10
#define ROW 10

static char	strike(char row, char col)
{
	char	shoot[3];
	char	result;
	char	tmp;

	shoot[0] = row + 'A';
	shoot[1] = col + '0';
	shoot[2] = '\n';
	tmp = 0;
	write(1, shoot, 3);
	read(0, &result, 1);
	while (tmp != '\n')
		read(0, &tmp, 1);
	return (result);
}

static void	shoot_shield(char *grid, char row, char col)
{
	int	i;
	int	j;

	j = row;
	while (j <= row + 2)
	{
		i = col - 2;
		while (i <= col + 2)
		{
			if (i >= 0 && i < COL && j >= 0 && j < ROW)
			{
				if (grid[j * COL + i] == '\0')
				{
					grid[j * COL + i] = strike(j, i);
				}
			}
			++i;
		}
		++j;
	}
}

static void	strike_all(char *grid)
{
	int	i;
	int	j;

	j = 0;
	while (j < ROW)
	{
		i = 0;
		while (i < COL)
		{
			if (grid[j * COL + i] == '\0' || grid[j * COL + i] == 'B')
			{
				grid[j * COL + i] = strike(j, i);
				if (grid[j * COL + i] == 'B')
				{
					shoot_shield(grid, j, i);
					grid[j * COL + i] = strike(j, i);
				}
			}
			++i;
		}
		++j;
	}
}

static void	init_grid(char *grid)
{
	int	i;

	i = 0;
	while (i < COL * ROW)
	{
		grid[i] = 0;
		++i;
	}
}

int			main(void)
{
	char	grid[COL * ROW];

	init_grid(grid);
	strike_all(grid);
	return (0);
}

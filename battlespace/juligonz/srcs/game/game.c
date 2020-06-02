/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:51:32 by juligonz          #+#    #+#             */
/*   Updated: 2020/06/02 16:02:40 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

void	sync_game(int column, int row)
{
	char	buffer[10];

	ft_bzero(buffer, 10);
	read(STDIN_FILENO, buffer, 10);
	buffer[ft_strlen(buffer) - 1] = '\0';
	if (ft_strcmp(buffer, "MISS") == 0)
		set_cell(column, row, '.');
	else if (ft_strcmp(buffer, "HIT") == 0)
		set_cell(column, row, 'H');
	else if (ft_strcmp(buffer, "SUNK") == 0)
		set_cell(column, row, 'S');
	else if (ft_strcmp(buffer, "BLOCKED") == 0)
		set_cell(column, row, 'B');
	else
		set_cell(column, row, '!');
}

void	play(int column, int row)
{
	char str[4];

	str[0] = row + 'A';
	str[1] = column + '0';
	str[2] = '\n';
	str[3] = '\0';
	write(STDOUT_FILENO, str, 3);
}

void	game_loop(void)
{
	size_t	row;
	size_t	column;

	row = -1;
	while (++row < 10)
	{
		column = -1;
		while (++column < 10)
		{
			play(column, row);
			sync_game(column, row);
		}
	}
	row = -1;
	while (++row < g_map.nb_cells)
		if (g_map.grid[row] == 'B')
		{
			play(row % g_map.size, row / g_map.size);
			sync_game(row % g_map.size, row / g_map.size);
		}
}

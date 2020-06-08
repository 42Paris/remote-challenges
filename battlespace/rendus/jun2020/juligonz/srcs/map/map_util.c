/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 18:17:53 by juligonz          #+#    #+#             */
/*   Updated: 2020/06/02 15:40:36 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

char			get_cell(int column, int row)
{
	return (g_map.grid[column + row * g_map.size]);
}

void			set_cell(int column, int row, char value)
{
	g_map.grid[column + row * g_map.size] = value;
}

void			print_map(void)
{
	char	str_map[g_map.nb_cells * 4 + g_map.size + 1];
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str_map[j++] = g_map.grid[0];
	str_map[j++] = ' ';
	while (++i < g_map.nb_cells)
	{
		if (i % g_map.size == 0)
			str_map[j++] = '\n';
		str_map[j++] = g_map.grid[i];
		str_map[j++] = ' ';
	}
	str_map[j] = '\0';
	write(STDERR_FILENO, str_map, j);
	write(STDERR_FILENO, "\n\n", 2);
}

void			print_position(int column, int row)
{
	char str[4];

	str[0] = row + 'A';
	str[1] = column + '0';
	str[2] = '\n';
	str[3] = '\0';
	write(STDERR_FILENO, str, 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 16:30:17 by juligonz          #+#    #+#             */
/*   Updated: 2020/06/01 19:26:51 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

t_map g_map;

char	*pos_to_str(int row, int column)
{
	static char response[4];

	response[0] = row + 'A';
	response[1] = column + '0';
	response[2] = '\n';
	return (response);
}

int		main(void)
{
	size_t	n;
	size_t	row;
	size_t	column;
	char	buffer[10];

	g_map = create_map(10);
	n = -1;
	while (++n < 2)
	{
		row = -1;
		while (++row < 10)
		{
			column = -1;
			while (++column < 10)
			{
				write(STDOUT_FILENO, pos_to_str(row, column), 3);
				read(STDIN_FILENO, buffer, 10);
				
			}
		}
	}
	destroy_map(g_map);
	return (0);
}

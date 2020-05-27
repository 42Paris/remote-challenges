/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 16:30:17 by juligonz          #+#    #+#             */
/*   Updated: 2020/05/27 18:43:22 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include "libft.h"

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
	return (0);
}

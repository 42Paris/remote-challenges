/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 23:56:46 by roalvare          #+#    #+#             */
/*   Updated: 2020/06/02 08:55:02 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	write_coord(char row, char colunm)
{
	char coord[3];

	coord[2] = '\n';
	coord[0] = row + 65;
	coord[1] = colunm + 48;
	write(1, coord, 3);
}

t_state	read_reponse(void)
{
	char *buf;

	buf = NULL;
	get_next_line(0, &buf);
	if (!ft_strncmp("MISS", buf, 4))
		return (MISS);
	else if (!ft_strncmp("HIT", buf, 3))
		return (HIT);
	else if (!ft_strncmp("BLOCKED", buf, 7))
		return (BLOCKED);
	else
		return (SUNK);
}

int		simple_attack(char board[100], int row, int column)
{
	char reponse;

	write_coord(row, column);
	reponse = read_reponse();
	board[column + row * 10] = reponse;
	return (reponse);
}

int		main(void)
{
	char	board[100];
	int		row;
	int		column;

	ft_bzero(board, 100);
	row = -1;
	while (++row < 10)
	{
		column = -1;
		while (++column < 10)
			simple_attack(board, row, column);
	}
	row = -1;
	while (++row < 10)
	{
		column = -1;
		while (++column < 10)
		{
			if (board[column + row * 10] == BLOCKED)
				simple_attack(board, row, column);
		}
	}
}

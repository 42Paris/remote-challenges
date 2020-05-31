/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 23:56:46 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/31 16:48:32 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	print_board(char board[100])
{
	int i = -1, j = -1;

	(void)board;
	while (i++ < 9)
	{
		j = -1;
		while (j++ < 9)
		{
			if (!board[j + i * 10])
				ft_putchar_fd('.', 2);
			else
				ft_putchar_fd(board[j + i * 10] + 48, 2);
			ft_putstr_fd(" ", 2);
		}
		ft_putchar_fd('\n', 2);
	}
	
}

void	fill_ship(t_box *ships[9])
{
	ships[FREGATE] = create_fregate();
	ships[DESTROYER] = create_destroyer();
	ships[CRUISER] = create_cruiser();
	ships[CARRIER] = create_carrier();
	ships[STATION] = create_station();
	ships[SQUARE] = create_square();
	ships[MOTHER_SHIP] = create_mother_ship();
	ships[HOLE] = create_hole();
	ships[BLOCKER] = create_blocker();
}

void	fill_armies(t_army *armies)
{
	armies->nation[0] = FREGATE;
	armies->nation[1] = DESTROYER;
	armies->nation[2] = DESTROYER;
	armies->nation[3] = CRUISER;
	armies->nation[4] = CARRIER;
	armies->mercenaries[0] = FREGATE;
	armies->mercenaries[0] = DESTROYER;
	armies->mercenaries[0] = DESTROYER;
	armies->mercenaries[0] = SQUARE;
	armies->mercenaries[0] = STATION;
	armies->aliens[0] = FREGATE;
	armies->aliens[1] = BLOCKER;
	armies->aliens[2] = BLOCKER;
	armies->aliens[3] = HOLE;
	armies->aliens[4] = MOTHER_SHIP;
}

void	write_coord(char row, char colunm)
{
	char coord[3];

	coord[2] = '\n';
	coord[0] = row + 65;
	coord[1] = colunm + 48;
	write(1, coord, 3);
	write(2, coord, 2);
}

t_state		read_reponse()
{
	char *buf;
	
	buf = NULL;
	get_next_line(0, &buf);
	ft_putstr_fd(" : ", 2);
	ft_putendl_fd(buf, 2);
	if (!ft_strncmp("MISS", buf, 4))
		return (MISS);
	else if (!ft_strncmp("HIT", buf, 3))
		return (HIT);
	else if (!ft_strncmp("BLOCKED", buf, 7))
		return (BLOCKED);
	else
		return (SUNK);
}

void	attack_random(int *row, int *column, char board[100])
{
	while(1)
	{
		*row = rand() % 10;
		*column = rand() % 10;

		if (!board[*column + *row * 10])
			break;
		// {
		// 	write_coord(*row, *column);
		// 	board[*column + *row * 10] = (char)read_reponse;
		// 	return (board[*column + *row * 10]);
		// }
	}
}

int		check_shield(char board[100], int row, int column)
{
	if (row != 0 && board[column + (row - 1) * 10] == BLOCKED)
		return (1);
	if (row != 9 && board[column + (row + 1) * 10] == BLOCKED)
		return (1);
	if (column != 0 && board[column - 1 + row * 10] == BLOCKED)
		return (1);
	if (column != 9 && board[column + 1 + row * 10] == BLOCKED)
		return (1);
	if (row != 0 && column != 0 && board[column - 1 + (row - 1) * 10] == BLOCKED)
		return (1);
	if (row != 0 && column != 9 && board[column + 1 + (row - 1) * 10] == BLOCKED)
		return (1);
	if (row != 9 && column != 0 && board[column - 1 + (row + 1) * 10] == BLOCKED)
		return (1);
	if (row != 9 && column != 9 && board[column + 1 + (row + 1) * 10] == BLOCKED)
		return (1);
	return (0);
}

int		is_empty(char board[100], int row, int column)
{
	if (row != 0 && board[column + (row - 1) * 10] != NONE)
		return (0);
	if (row != 9 && board[column + (row + 1) * 10] != NONE)
		return (0);
	if (column != 0 && board[column - 1 + row * 10] != NONE)
		return (0);
	if (column != 9 && board[column + 1 + row * 10] != NONE)
		return (0);
	if (row != 0 && column != 0 && board[column - 1 + (row - 1) * 10] != NONE)
		return (0);
	if (row != 0 && column != 9 && board[column + 1 + (row - 1) * 10] != NONE)
		return (0);
	if (row != 9 && column != 0 && board[column - 1 + (row + 1) * 10] != NONE)
		return (0);
	if (row != 9 && column != 9 && board[column + 1 + (row + 1) * 10] != NONE)
		return (0);
	return (1);
}

int	simple_attack(char board[100], int row, int column)
{
	char reponse;

	write_coord(row, column);
	reponse = read_reponse();
	board[column + row * 10] = reponse;
	return (reponse);
}

void	attack_blocked(char board[100], int row, int column)
{
	int i;
	int j;

	ft_putstr_fd("BREAK THE SHIELD !\n", 2);
	i = row - 2;
	if (i < 0)
		i = 0;
	while (i < row + 2 && i < 10)
	{
		j = column - 2;
		if (j < 0)
			j = 0;
		while (j < column + 2 && j < 10)
		{
			if (board[j + i * 10] == BLOCKED)
				simple_attack(board, i, j);
			j++;
		}
		i++;
	}
}

void	attack(char board[100], int row, int column)
{
	char reponse;

	if (board[column + row * 10] != NONE)
		return ;
	write_coord(row, column);
	reponse = read_reponse();
	board[column + row * 10] = reponse;
	if (reponse == SUNK)
	{
		if (check_shield(board, row, column) || is_empty(board, row, column))
		{
			board[column + row * 10] = SHIELD;
			attack_blocked(board, row, column);
		}
		else
			board[column + row * 10] = HIT;
	}
	else if (reponse == HIT || reponse == BLOCKED)
	{
		if (row != 0)
			attack(board, row - 1, column);
		if (row != 9)
			attack(board, row + 1, column);
		if (column != 0)
			attack(board, row, column - 1);
		if (column != 9)
			attack(board, row, column + 1);
		if (row != 0 && column != 0)
			attack(board, row - 1, column - 1);
		if (row != 0 && column != 9)
			attack(board, row - 1, column + 1);
		if (row != 9 && column != 0)
			attack(board, row + 1, column - 1);
		if (row != 9 && column != 9)
			attack(board, row + 1, column + 1);
	}
}

void strat(char board[100])
{
	int	row;
	int	column;

	// attack_random(&row, &column, board);
	row = 4;
	column = 4;
	attack(board, row, column);
}


int		main()
{
	char board[100];
	t_box	*ships[9];
	t_army	armies;
	int		shield;
	int		extend;

	shield = 1;
	extend = 0;
	ft_bzero(board, 100);
	ft_bzero(&armies, sizeof(t_army));
	fill_ship(ships);
	fill_armies(&armies);
	// print_board(board);

	// t_list *lst = NULL;
	// box_suffixe(ships[STATION], &lst);
	
	int i = -1;
	struct timeval tv;
	gettimeofday(&tv,NULL);
	srand((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
	while (++i < 1)
	{
		strat(board);
	}
	print_board(board);
	// print_box(root);
	// print_box(root->near[UP]);
}
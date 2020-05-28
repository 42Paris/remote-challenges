/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 23:56:46 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/29 01:49:42 by roalvare         ###   ########.fr       */
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
			ft_printf("%d, ", board[j + i * 10]);
		ft_putchar_fd('\n', 1);
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

int		main()
{
	char board[100];
	t_box	*ships[9];
	t_army	armies;

	ft_bzero(board, 100);
	ft_bzero(&armies, sizeof(t_army));
	fill_ship(ships);
	fill_armies(&armies);
	// print_board(board);

	t_box *root;
	root = create_box();
	add_box(root, UP);
	add_box(root, LEFT);
	t_list *lst = NULL;
	box_suffixe(ships[STATION], &lst);
	// print_box(root);
	// print_box(root->near[UP]);
}
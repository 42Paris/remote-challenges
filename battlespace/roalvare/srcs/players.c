/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 23:56:46 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/28 20:42:41 by roalvare         ###   ########.fr       */
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
}

void	fill_armies(t_army *armies)
{
	armies->nation[0] = FREGATE;
	armies->nation[1] = DESTROYER;
	armies->nation[2] = DESTROYER;
	armies->nation[3] = CRUISER;
	armies->nation[4] = CARRIER;
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
	box_suffixe(ships[CARRIER], &lst);
	// print_box(root);
	// print_box(root->near[UP]);
}
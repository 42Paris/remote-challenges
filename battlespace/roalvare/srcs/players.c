/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 23:56:46 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/28 11:19:07 by roalvare         ###   ########.fr       */
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

int		main()
{
	char board[100];

	ft_bzero(board, 100);
	// print_board(board);

	t_box *root;
	root = create_box();
	add_box(root, UP);
	add_box(root, LEFT);
	t_list *lst = NULL;
	box_suffixe(root, &lst);
	// print_box(root);
	// print_box(root->near[UP]);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btsp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:47:21 by mchardin          #+#    #+#             */
/*   Updated: 2020/06/02 23:06:30 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

int
	fill_all(t_btsp *btsp, t_box box, int rev,
	int (*ft_solve)(t_btsp *, t_idx, t_box))
{
	t_idx		idx;
	t_idx		inv_idx;

	idx.i = 4;
	idx.j = 5;
	while (idx.i < 10 && idx.j < 10)
	{
		idx.i++;
		inv_idx.i = idx.j;
		inv_idx.j = idx.i;
		if (((idx.i + idx.j) % 2 == rev
		|| (idx.i < 4 && idx.j < 4) || btsp->alien)
			&& (four_moves(btsp, idx, box, ft_solve) < 0 ||
			four_moves(btsp, inv_idx, box, ft_solve) < 0))
			return (0);
		if (idx.i == idx.j)
		{
			idx.j++;
			idx.i = 4;
		}
	}
	return (1);
}

int
	first_moves(t_btsp *btsp)
{
	int				ret[3];
	static t_idx	first_boxes[] = {{2, 2}, {1, 4}, {4, 3}, {1, 7}, {4, 0}};

	if ((ret[0] = four_moves(btsp, first_boxes[0], UNKNOWN, ft_solve)) < 0
	|| (ret[1] = four_moves(btsp, first_boxes[1], UNKNOWN, ft_solve)) < 0
	|| (ret[2] = four_moves(btsp, first_boxes[2], UNKNOWN, ft_solve)) < 0)
		return (0);
	if (ret[0] + ret[1] + ret[2] == 0
	&& four_moves(btsp, first_boxes[3], UNKNOWN, ft_solve) < 0)
		return (0);
	if (four_moves(btsp, first_boxes[4], UNKNOWN, ft_solve) < 0)
		return (0);
	return (1);
}

int
	main(void)
{
	t_btsp		btsp;

	ft_bzero(&btsp, sizeof(t_btsp));
	ft_memset(&btsp.last_hit, -1, sizeof(t_idx));
	ft_memset(&btsp.ship, -1, sizeof(btsp.ship));
	first_moves(&btsp);
	fill_all(&btsp, UNKNOWN, 1, ft_solve);
	fill_all(&btsp, UNKNOWN, 0, ft_solve);
	fill_all(&btsp, BLOCKED, 1, 0);
	fill_all(&btsp, BLOCKED, 0, 0);
	fill_all(&btsp, PROB_EMPTY, 1, 0);
	fill_all(&btsp, PROB_EMPTY, 0, 0);
	fill_all(&btsp, BLOCKED, 1, 0);
	fill_all(&btsp, BLOCKED, 0, 0);
	return (0);
}

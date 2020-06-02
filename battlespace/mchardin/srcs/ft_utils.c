/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 10:40:14 by mchardin          #+#    #+#             */
/*   Updated: 2020/06/02 22:57:51 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

int
	is_in_map(int i, int j)
{
	if (i < 0 || i > 9 || j < 0 || j > 9)
		return (0);
	return (1);
}

int
	is_box(t_btsp btsp, int i, int j, t_box box)
{
	if (is_in_map(i, j) && btsp.map[i][j] == box)
		return (1);
	return (0);
}

t_idx
	add_to_idx(t_idx idx, int i_add, int j_add)
{
	t_idx	ret;

	ret.i = idx.i + i_add;
	ret.j = idx.j + j_add;
	return (ret);
}

int
	next_solve(t_btsp *btsp, t_idx next)
{
	if (is_box(*btsp, next.i, next.j, UNKNOWN)
		&& !check_later(*btsp, next.i, next.j))
	{
		move_n_solve(btsp, next.i, next.j, ft_solve);
		return (1);
	}
	return (0);
}

int
	is_mine(t_btsp *btsp, t_idx idx)
{
	int		count;

	count = count_around(*btsp, btsp->ship[0], EMPTY)
	+ count_around(*btsp, btsp->ship[0], PROB_EMPTY)
	+ count_around(*btsp, btsp->ship[0], SHIELD);
	if (count == 8
	|| (count == 5 && (!idx.i || !idx.j || idx.i == 9 || idx.j == 9))
	|| (count == 3 && (!idx.i || idx.i == 9) && (!idx.j || idx.j == 9)))
		return (1);
	return (0);
}

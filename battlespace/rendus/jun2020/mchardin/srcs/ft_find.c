/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 20:59:41 by mchardin          #+#    #+#             */
/*   Updated: 2020/06/02 12:58:21 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

int
	count_around(t_btsp btsp, t_idx idx, t_box box)
{
	int		count;

	count = 0;
	count += is_box(btsp, idx.i - 1, idx.j, box);
	count += is_box(btsp, idx.i, idx.j - 1, box);
	count += is_box(btsp, idx.i + 1, idx.j, box);
	count += is_box(btsp, idx.i, idx.j + 1, box);
	count += is_box(btsp, idx.i - 1, idx.j - 1, box);
	count += is_box(btsp, idx.i - 1, idx.j + 1, box);
	count += is_box(btsp, idx.i + 1, idx.j + 1, box);
	count += is_box(btsp, idx.i + 1, idx.j - 1, box);
	return (count);
}

t_idx
	step_to(t_btsp *btsp, t_idx idx, t_box box, int skip)
{
	if (is_box(*btsp, idx.i - 1, idx.j, box) && skip < 1)
		return (add_to_idx(idx, -1, 0));
	else if (is_box(*btsp, idx.i, idx.j - 1, box) && skip < 2)
		return (add_to_idx(idx, 0, -1));
	else if (is_box(*btsp, idx.i + 1, idx.j, box) && skip < 3)
		return (add_to_idx(idx, 1, 0));
	else if (is_box(*btsp, idx.i, idx.j + 1, box) && skip < 4)
		return (add_to_idx(idx, 0, 1));
	else if (is_box(*btsp, idx.i - 1, idx.j - 1, box) && skip < 5)
		return (add_to_idx(idx, -1, -1));
	else if (is_box(*btsp, idx.i - 1, idx.j + 1, box) && skip < 6)
		return (add_to_idx(idx, -1, 1));
	else if (is_box(*btsp, idx.i + 1, idx.j + 1, box) && skip < 7)
		return (add_to_idx(idx, 1, 1));
	else if (is_box(*btsp, idx.i + 1, idx.j - 1, box))
		return (add_to_idx(idx, 1, -1));
	else
		return (idx);
}

t_idx
	find_box(t_btsp btsp, t_box box)
{
	t_idx		idx;

	idx.i = 0;
	while (idx.i < 10)
	{
		idx.j = 0;
		while (idx.j < 10)
		{
			if (btsp.map[idx.i][idx.j] == box)
				return (idx);
			idx.j++;
		}
		idx.i++;
	}
	idx.i = -1;
	return (idx);
}

int
	count_boxes(t_btsp btsp, t_box box)
{
	t_idx		idx;
	int			count;

	idx.i = 0;
	count = 0;
	while (idx.i < 10)
	{
		idx.j = 0;
		while (idx.j < 10)
		{
			if (btsp.map[idx.i][idx.j] == box)
				count++;
			idx.j++;
		}
		idx.i++;
	}
	return (count);
}

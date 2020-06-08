/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_line.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 11:30:53 by mchardin          #+#    #+#             */
/*   Updated: 2020/06/02 23:05:59 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

int
	longest_line(t_idx lines[10], t_line *dir)
{
	int			i;
	int			ret;

	i = -1;
	ret = 0;
	while (++i < 10)
	{
		if ((lines[i].i > lines[ret].i && *dir == HORIZONTAL)
		|| (lines[i].i > lines[ret].j && *dir == VERTICAL))
		{
			*dir = HORIZONTAL;
			ret = i;
		}
		if ((lines[i].j > lines[ret].i && *dir == HORIZONTAL)
		|| (lines[i].j > lines[ret].j && *dir == VERTICAL))
		{
			*dir = VERTICAL;
			ret = i;
		}
	}
	return (ret);
}

t_idx
	line_start(t_idx ship[5], t_line *dir, int ret)
{
	int		i;

	i = 0;
	while (ship[i].i >= 0)
	{
		if ((*dir == VERTICAL && ship[i].j == ret)
		|| (*dir == HORIZONTAL && ship[i].i == ret))
			return (ship[i]);
		i++;
	}
	return (ship[i]);
}

t_idx
	find_line(t_idx ship[5], t_line *dir, int *len, int *size)
{
	t_idx		lines[10];
	int			ret;

	ft_bzero(&lines, sizeof(lines));
	while (ship[*size].i >= 0)
	{
		lines[ship[*size].i].i++;
		lines[ship[*size].j].j++;
		*size += 1;
	}
	ret = longest_line(lines, dir);
	*len = lines[ret].i > lines[ret].j ? lines[ret].i : lines[ret].j;
	return (line_start(ship, dir, ret));
}

int
	fill_line(t_btsp *btsp, t_line dir, t_idx line)
{
	t_idx	next;
	t_idx	add;
	int		skip;
	int		add_to;

	skip = 0;
	add_to = -1;
	while (1)
	{
		add.i = dir == HORIZONTAL ? 0 : add_to;
		add.j = dir == HORIZONTAL ? add_to : 0;
		next = add_to_idx(line, add.i, add.j);
		if (add_to > 0 && ((!is_box(*btsp, next.i, next.j, UNKNOWN)
			&& !is_box(*btsp, next.i, next.j, HIT))
			|| !is_box(*btsp, next.i - !dir, next.j - dir, HIT)))
			return (1);
		if (next_solve(btsp, next))
			return (0);
		add_to++;
	}
	return (1);
}

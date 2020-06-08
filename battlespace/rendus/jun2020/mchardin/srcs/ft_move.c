/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 19:32:06 by mchardin          #+#    #+#             */
/*   Updated: 2020/06/02 23:07:35 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

t_box
	box_return(void)
{
	char		*str;
	int			ret;

	if (get_next_line(0, &str) < 0)
		return (UNKNOWN);
	if (!ft_strncmp(str, "HIT", 4))
		ret = HIT;
	else if (!ft_strncmp(str, "SUNK", 5))
		ret = SUNK;
	else if (!ft_strncmp(str, "MISS", 5))
		ret = EMPTY;
	else if (!ft_strncmp(str, "BLOCKED", 8))
		ret = BLOCKED;
	else
		ret = UNKNOWN;
	free(str);
	return (ret);
}

t_box
	one_move(t_btsp *btsp, t_idx idx)
{
	char		tmp[3];

	if (!is_in_map(idx.i, idx.j)
	|| btsp->map[idx.i][idx.j] == SUNK
	|| btsp->map[idx.i][idx.j] == EMPTY
	|| btsp->map[idx.i][idx.j] == HIT)
		return (KNOWN);
	tmp[0] = idx.i + 'A';
	tmp[1] = idx.j + '0';
	tmp[2] = '\n';
	write(1, &tmp, 3);
	btsp->map[idx.i][idx.j] = box_return();
	btsp->rounds++;
	return (btsp->map[idx.i][idx.j]);
}

int
	move_n_solve(t_btsp *btsp, int row, int column,
	int (*ft_solve)(t_btsp *, t_idx, t_box))
{
	t_box		ret;
	t_idx		idx;

	idx.i = row;
	idx.j = column;
	if (!(ret = one_move(btsp, idx)))
		return (-100);
	if (ret != KNOWN && ft_solve)
		return (ft_solve(btsp, idx, ret));
	else
		return (1);
}

int
	four_moves(t_btsp *btsp, t_idx idx, t_box box,
	int (*ft_solve)(t_btsp *, t_idx, t_box))
{
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	if (!is_in_map(idx.i, idx.j))
		return (0);
	if (btsp->map[idx.i][idx.j] == box
		&& !check_later(*btsp, idx.i, idx.j))
		ret += move_n_solve(btsp, idx.i, idx.j, ft_solve);
	if (btsp->map[idx.j][9 - idx.i] == box
		&& !check_later(*btsp, idx.j, 9 - idx.i))
		ret += move_n_solve(btsp, idx.j, 9 - idx.i, ft_solve);
	if (btsp->map[9 - idx.i][9 - idx.j] == box
		&& !check_later(*btsp, 9 - idx.i, 9 - idx.j))
		ret += move_n_solve(btsp, 9 - idx.i, 9 - idx.j, ft_solve);
	if (btsp->map[9 - idx.j][idx.i] == box
		&& !check_later(*btsp, 9 - idx.j, idx.i))
		ret += move_n_solve(btsp, 9 - idx.j, idx.i, ft_solve);
	return (ret < 0 ? -1 : ret);
}

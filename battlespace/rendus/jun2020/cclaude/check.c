/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 11:27:41 by cclaude           #+#    #+#             */
/*   Updated: 2020/06/02 11:51:25 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

int		check_spot(char *marks, char map[10][10], int i, int j)
{
	if (i < 0 || i > 9 || j < 0 || j > 9)
		return (0);
	else
		return (ft_strchr(marks, map[i][j]));
}

int		check_line(char mp[10][10], int i, int j)
{
	if (check_spot("x", mp, i, j - 1) && check_spot("x", mp, i, j - 2))
		return (1);
	if (check_spot("x", mp, i, j + 1) && check_spot("x", mp, i, j + 2))
		return (1);
	if (check_spot("x", mp, i - 1, j) && check_spot("x", mp, i - 2, j))
		return (1);
	if (check_spot("x", mp, i + 1, j) && check_spot("x", mp, i + 2, j))
		return (1);
	if (check_spot("x", mp, i - 1, j - 1) && check_spot("x", mp, i - 2, j - 2))
		return (1);
	if (check_spot("x", mp, i - 1, j + 1) && check_spot("x", mp, i - 2, j + 2))
		return (1);
	if (check_spot("x", mp, i + 1, j - 1) && check_spot("x", mp, i + 2, j - 2))
		return (1);
	if (check_spot("x", mp, i + 1, j + 1) && check_spot("x", mp, i + 2, j + 2))
		return (1);
	return (0);
}

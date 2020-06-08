/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sunk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 20:23:51 by cclaude           #+#    #+#             */
/*   Updated: 2020/06/02 10:49:55 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

void	clear_sides(char map[10][10], int i, int j)
{
	if (check_spot(".", map, i, j - 1))
		map[i][j - 1] = ' ';
	if (check_spot(".", map, i, j + 1))
		map[i][j + 1] = ' ';
	if (check_spot(".", map, i - 1, j))
		map[i - 1][j] = ' ';
	if (check_spot(".", map, i + 1, j))
		map[i + 1][j] = ' ';
	if (check_spot(".", map, i - 1, j - 1))
		map[i - 1][j - 1] = ' ';
	if (check_spot(".", map, i - 1, j + 1))
		map[i - 1][j + 1] = ' ';
	if (check_spot(".", map, i + 1, j - 1))
		map[i + 1][j - 1] = ' ';
	if (check_spot(".", map, i + 1, j + 1))
		map[i + 1][j + 1] = ' ';
}

void	mark_sunk(char map[10][10], int i, int j)
{
	map[i][j] = 'o';
	if (check_spot("x", map, i, j - 1))
		mark_sunk(map, i, j - 1);
	if (check_spot("x", map, i, j + 1))
		mark_sunk(map, i, j + 1);
	if (check_spot("x", map, i - 1, j))
		mark_sunk(map, i - 1, j);
	if (check_spot("x", map, i + 1, j))
		mark_sunk(map, i + 1, j);
	if (check_spot("x", map, i - 1, j - 1))
		mark_sunk(map, i - 1, j - 1);
	if (check_spot("x", map, i - 1, j + 1))
		mark_sunk(map, i - 1, j + 1);
	if (check_spot("x", map, i + 1, j - 1))
		mark_sunk(map, i + 1, j - 1);
	if (check_spot("x", map, i + 1, j + 1))
		mark_sunk(map, i + 1, j + 1);
	clear_sides(map, i, j);
}

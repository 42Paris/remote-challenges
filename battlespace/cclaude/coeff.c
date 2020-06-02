/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coeff.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 20:27:47 by cclaude           #+#    #+#             */
/*   Updated: 2020/06/02 12:17:23 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

int		find_max(char map[10][10], int pdf[10][10])
{
	int	max;
	int	i;
	int	j;

	max = 0;
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (pdf[i][j] > max && map[i][j] == '.')
				max = pdf[i][j];
			j++;
		}
		i++;
	}
	return (max);
}

void	find_target(char map[10][10], int pdf[10][10], int *i, int *j)
{
	int	max;

	max = find_max(map, pdf);
	*i = 0;
	while (*i < 10)
	{
		*j = 0;
		while (*j < 10)
		{
			if (pdf[*i][*j] == max && map[*i][*j] == '.')
				break ;
			(*j)++;
		}
		if (*j < 10 && pdf[*i][*j] == max && map[*i][*j] == '.')
			break ;
		(*i)++;
	}
}

int		compute_coeff(char map[10][10], int i, int j)
{
	int	n;

	if (check_spot("b.", map, i, j) == 0)
		return (0);
	n = 9 - ft_abs((float)i - 4.5) - ft_abs((float)j - 4.5);
	n += (check_spot(".", map, i, j - 1)) ? 6 : 0;
	n += (check_spot(".", map, i, j + 1)) ? 6 : 0;
	n += (check_spot(".", map, i - 1, j)) ? 6 : 0;
	n += (check_spot(".", map, i + 1, j)) ? 6 : 0;
	n += (check_spot(".", map, i - 1, j - 1)) ? 2 : 0;
	n += (check_spot(".", map, i - 1, j + 1)) ? 2 : 0;
	n += (check_spot(".", map, i + 1, j - 1)) ? 2 : 0;
	n += (check_spot(".", map, i + 1, j + 1)) ? 2 : 0;
	n += (check_spot(".", map, i, j - 2)) ? 2 : 0;
	n += (check_spot(".", map, i, j + 2)) ? 2 : 0;
	n += (check_spot(".", map, i - 2, j)) ? 2 : 0;
	n += (check_spot(".", map, i + 2, j)) ? 2 : 0;
	n += (check_spot(".", map, i - 2, j - 2)) ? 1 : 0;
	n += (check_spot(".", map, i - 2, j + 2)) ? 1 : 0;
	n += (check_spot(".", map, i + 2, j - 2)) ? 1 : 0;
	n += (check_spot(".", map, i + 2, j + 2)) ? 1 : 0;
	return (n);
}

void	map_coeff(char map[10][10], int pdf[10][10])
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			pdf[i][j] = compute_coeff(map, i, j);
			j++;
		}
		i++;
	}
}

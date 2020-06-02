/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:11:37 by memartin          #+#    #+#             */
/*   Updated: 2020/06/01 12:46:31 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/btsp.h"

void		reset_shield_grid(t_data *d)
{
	int			i;
	int			j;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
			d->shield[j][i++] = 1;
		j++;
	}
}

void		reset_hit(t_data *d)
{
	int			i;

	i = 0;
	d->nb_hit = 0;
	while (i <= 6)
		d->hit[i++] = 0;
}

int			**init_grid(int nb)
{
	int			**grid;
	int			i;
	int			j;

	i = 0;
	if (!(grid = (int**)malloc(sizeof(int*) * 10)))
		return (0);
	while (i < 10)
	{
		j = 0;
		if (!(grid[i] = (int*)malloc(sizeof(int) * 10)))
			return (0);
		while (j < 10)
			grid[i][j++] = nb;
		i++;
	}
	return (grid);
}

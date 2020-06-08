/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 12:16:45 by memartin          #+#    #+#             */
/*   Updated: 2020/05/31 18:55:04 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/btsp.h"

void		set_suffix_move(t_data *d)
{
	d->move[2] = '\n';
	d->move[3] = '\0';
}

int			nb_possible_shield(int **map)
{
	int		i;
	int		j;
	int		res;

	res = 0;
	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			if (map[j][i] == 1)
				res++;
			i++;
		}
		j++;
	}
	return (res);
}

void		set_move_shield(t_data *d, int count)
{
	int		i;
	int		j;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			if (d->shield[j][i] != 1)
				i++;
			else
			{
				if (count == 0)
				{
					d->move[0] = 'A' + j;
					d->move[1] = '0' + i;
					return ;
				}
				count--;
				i++;
			}
		}
		j++;
	}
}

void		set_highest_prob(t_data *d)
{
	int		i;
	int		j;

	j = 0;
	d->highest_prob = 0;
	d->nb_prob = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			if (d->weight[j][i] > d->highest_prob)
			{
				d->highest_prob = d->weight[j][i];
				d->nb_prob = 1;
			}
			else if (d->weight[j][i] == d->highest_prob)
				d->nb_prob++;
			i++;
		}
		j++;
	}
}

void		set_move(t_data *d, int count, int nb)
{
	int		i;
	int		j;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			if (d->weight[j][i] != nb)
				i++;
			else
			{
				if (count == 0)
				{
					d->move[0] = 'A' + j;
					d->move[1] = '0' + i;
					return ;
				}
				count--;
				i++;
			}
		}
		j++;
	}
}

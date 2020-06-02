/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weight.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 18:00:29 by memartin          #+#    #+#             */
/*   Updated: 2020/05/28 20:03:14 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/btsp.h"

static void		set_weight_data(t_weight_data *d, int x, int y, int ray)
{
	d->xmin = x - ray;
	if (d->xmin < 0)
		d->xmin = 0;
	d->ymin = y - ray;
	if (d->ymin < 0)
		d->ymin = 0;
	d->xmax = x + ray;
	if (d->xmax > 9)
		d->xmax = 9;
	d->ymax = y + ray;
	if (d->ymax > 9)
		d->ymax = 9;
	d->max_res = (d->xmax + 1 - d->xmin) * (d->ymax + 1 - d->ymin);
}

static int		get_square_value(int **map, t_weight_data *d)
{
	int		i;
	int		j;
	int		res;

	j = d->ymin;
	res = 0;
	while (j <= d->ymax)
	{
		i = d->xmin;
		while (i <= d->xmax)
		{
			if (map[j][i] == 0)
				res++;
			i++;
		}
		j++;
	}
	return (res);
}

static int		get_weight(int **map, int x, int y)
{
	t_weight_data	data;
	int				res;

	if (map[y][x] == 1)
		return (0);
	else if (map[y][x] == 3)
		return (50);
	set_weight_data(&data, x, y, 1);
	res = get_square_value(map, &data);
	if (res == data.max_res)
	{
		set_weight_data(&data, x, y, 2);
		return (get_square_value(map, &data));
	}
	return (res);
}

void			set_weight(t_data *d)
{
	int		i;
	int		j;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			d->weight[j][i] = get_weight(d->map, i, j);
			i++;
		}
		j++;
	}
}

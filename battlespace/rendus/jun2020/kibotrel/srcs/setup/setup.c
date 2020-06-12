/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 02:54:32 by kibotrel          #+#    #+#             */
/*   Updated: 2020/06/01 21:58:03 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/time.h>
#include "structs.h"
#include "utils.h"

uint8_t	setup(t_env *env)
{
	uint8_t			cell;
	struct timeval	time;

	cell = 0;
	ft_bzero(env, sizeof(t_env));
	ft_bzero(&env->stack, sizeof(t_cell) * 100);
	clear_2d_array(env->grid);
	env->ships = 5;
	env->mode = 0;
	env->remaining_shots = 100;
	gettimeofday(&time, NULL);
	srand(time.tv_usec);
	if (!(env->spots = malloc(sizeof(uint8_t) * 100)))
		return (0);
	while (cell < 100)
	{
		env->spots[cell] = cell;
		env->stack[cell] = (t_cell){10, 0};
		cell++;
	}
	env->protected = 1;
	return (1);
}

void	setup_shield(t_area *protected, t_cell cell)
{
	uint8_t			i;
	t_cell			pos;

	i = 0;
	protected->min.y = cell.y < 2 ? 0 : cell.y - 2;
	protected->min.x = cell.x < 2 ? 0 : cell.x - 2;
	protected->max.y = cell.y > 7 ? 9 : cell.y + 2;
	protected->max.x = cell.x > 7 ? 9 : cell.x + 2;
	protected->current = protected->min;
	protected->remaining_shots = area_2d(protected->min, protected->max) - 1;
	protected->spots = malloc(sizeof(uint8_t) * protected->remaining_shots);
	pos = protected->min;
	while (pos.y <= protected->max.y)
	{
		pos.x = protected->min.x;
		while (pos.x <= protected->max.x)
		{
			if (pos.y * 10 + pos.x != cell.y * 10 + cell.x)
				protected->spots[i++] = pos.y * 10 + pos.x;
			pos.x++;
		}
		pos.y++;
	}
}

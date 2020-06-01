/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 03:53:48 by kibotrel          #+#    #+#             */
/*   Updated: 2020/06/01 22:18:01 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core.h"
#include "setup.h"
#include "utils.h"

void	destroy_shield(t_env *env, t_cell cell)
{
	char	response[9];
	t_area	protected;

	setup_shield(&protected, cell);
	while (protected.remaining_shots > 0)
	{
		protected.current = pick_random_shield(&protected);
		fire_on(protected.current, response);
		if (!ft_strcmp(response, "SUNK\n"))
		{
			free(protected.spots);
			env->grid[protected.current.y][protected.current.x] = 4;
			break ;
		}
	}
	fire_on(cell, response);
	handle_response(env, response, cell);
}

void	update_grid(t_env *env, t_cell cell, uint8_t state)
{
	t_cell	stack[100];
	uint8_t	i;

	env->grid[cell.y][cell.x] = state;
	if (state == 3 && env->protected == 0)
	{
		i = 0;
		while (i < 100)
			stack[i++] = (t_cell){10, 0};
		find_sunk(env, stack);
		optimize_grid(env, stack);
	}
}

void	update_stack(t_env *env, t_cell cell)
{
	uint8_t	i;

	i = stack_index(env);
	if (cell.x > 0 && env->grid[cell.y][cell.x - 1] == 0)
		i = secure_stack(env, i, (t_cell){cell.y, cell.x - 1});
	if (cell.y > 0 && env->grid[cell.y - 1][cell.x] == 0)
		i = secure_stack(env, i, (t_cell){cell.y - 1, cell.x});
	if (cell.x < 9 && env->grid[cell.y][cell.x + 1] == 0)
		i = secure_stack(env, i, (t_cell){cell.y, cell.x + 1});
	if (cell.y < 9 && env->grid[cell.y + 1][cell.x] == 0)
		i = secure_stack(env, i, (t_cell){cell.y + 1, cell.x});
	if (cell.x > 0 && cell.y > 0 && env->grid[cell.y - 1][cell.x - 1] == 0)
		i = secure_stack(env, i, (t_cell){cell.y - 1, cell.x - 1});
	if (cell.x < 9 && cell.y < 9 && env->grid[cell.y + 1][cell.x + 1] == 0)
		i = secure_stack(env, i, (t_cell){cell.y + 1, cell.x + 1});
	if (cell.x < 9 && cell.y > 0 && env->grid[cell.y - 1][cell.x + 1] == 0)
		i = secure_stack(env, i, (t_cell){cell.y - 1, cell.x + 1});
	if (cell.x > 0 && cell.y < 9 && env->grid[cell.y + 1][cell.x - 1] == 0)
		i = secure_stack(env, i, (t_cell){cell.y + 1, cell.x - 1});
}

t_cell	target_mode(t_env *env)
{
	t_cell	cell;
	uint8_t	i;

	i = stack_index(env);
	if (i > 0)
		i--;
	else
	{
		env->mode = 0;
		return (pick_random_cell(env));
	}
	cell = env->stack[i];
	update_remaining_shots(env, cell.y * 10 + cell.x);
	env->stack[i] = (t_cell){10, 0};
	return (cell);
}

uint8_t	shield_or_ship(t_env *env)
{
	uint8_t	i;
	uint8_t	state;

	if (env->mode == 1)
	{
		state = 3;
		env->ships--;
		env->mode = 0;
		while (i < 100)
			env->stack[i++] = (t_cell){10, 0};
	}
	else
	{
		state = 4;
		env->protected = 0;
	}
	return (state);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 20:03:24 by kibotrel          #+#    #+#             */
/*   Updated: 2020/06/01 22:15:12 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "utils.h"

void		update_stack2(t_env *env, t_cell stack[100], t_cell cell)
{
	uint8_t	i;

	i = stack_index2(stack);
	if (cell.x > 0 && env->grid[cell.y][cell.x - 1] == 2)
		i = secure_stack2(stack, i, (t_cell){cell.y, cell.x - 1});
	if (cell.y > 0 && env->grid[cell.y - 1][cell.x] == 2)
		i = secure_stack2(stack, i, (t_cell){cell.y - 1, cell.x});
	if (cell.x < 9 && env->grid[cell.y][cell.x + 1] == 2)
		i = secure_stack2(stack, i, (t_cell){cell.y, cell.x + 1});
	if (cell.y < 9 && env->grid[cell.y + 1][cell.x] == 2)
		i = secure_stack2(stack, i, (t_cell){cell.y + 1, cell.x});
	if (cell.x > 0 && cell.y > 0 && env->grid[cell.y - 1][cell.x - 1] == 2)
		i = secure_stack2(stack, i, (t_cell){cell.y - 1, cell.x - 1});
	if (cell.x < 9 && cell.y < 9 && env->grid[cell.y + 1][cell.x + 1] == 2)
		i = secure_stack2(stack, i, (t_cell){cell.y + 1, cell.x + 1});
	if (cell.x < 9 && cell.y > 0 && env->grid[cell.y - 1][cell.x + 1] == 2)
		i = secure_stack2(stack, i, (t_cell){cell.y - 1, cell.x + 1});
	if (cell.x > 0 && cell.y < 9 && env->grid[cell.y + 1][cell.x - 1] == 2)
		i = secure_stack2(stack, i, (t_cell){cell.y + 1, cell.x - 1});
	secure_stack2(stack, i, cell);
}

static void	remove_cell(t_env *env, t_cell excluded)
{
	env->grid[excluded.y][excluded.x] = 1;
	update_remaining_shots(env, excluded.y * 10 + excluded.x);
}

void		predict_future(t_env *env, t_cell cell)
{
	if (cell.x > 0 && env->grid[cell.y][cell.x - 1] == 0)
		remove_cell(env, (t_cell){cell.y, cell.x - 1});
	if (cell.y > 0 && env->grid[cell.y - 1][cell.x] == 0)
		remove_cell(env, (t_cell){cell.y - 1, cell.x});
	if (cell.x < 9 && env->grid[cell.y][cell.x + 1] == 0)
		remove_cell(env, (t_cell){cell.y, cell.x + 1});
	if (cell.y < 9 && env->grid[cell.y + 1][cell.x] == 0)
		remove_cell(env, (t_cell){cell.y + 1, cell.x});
	if (cell.x > 0 && cell.y > 0 && env->grid[cell.y - 1][cell.x - 1] == 0)
		remove_cell(env, (t_cell){cell.y - 1, cell.x - 1});
	if (cell.x < 9 && cell.y < 9 && env->grid[cell.y + 1][cell.x + 1] == 0)
		remove_cell(env, (t_cell){cell.y + 1, cell.x + 1});
	if (cell.x < 9 && cell.y > 0 && env->grid[cell.y - 1][cell.x + 1] == 0)
		remove_cell(env, (t_cell){cell.y - 1, cell.x + 1});
	if (cell.x > 0 && cell.y < 9 && env->grid[cell.y + 1][cell.x - 1] == 0)
		remove_cell(env, (t_cell){cell.y + 1, cell.x - 1});
}

void		find_sunk(t_env *env, t_cell stack[100])
{
	t_cell	current;

	current = (t_cell){0, 0};
	while (current.y < 10)
	{
		current.x = 0;
		while (current.x < 10)
		{
			if (env->grid[current.y][current.x] == 3)
				update_stack2(env, stack, current);
			current.x++;
		}
		current.y++;
	}
}

void		optimize_grid(t_env *env, t_cell stack[100])
{
	uint8_t	i;

	i = 0;
	while (stack[i].y < 10)
		update_stack2(env, stack, stack[i++]);
	i = 0;
	while (stack[i].y < 10)
	{
		env->grid[stack[i].y][stack[i].x] = 3;
		predict_future(env, stack[i]);
		i++;
	}
}

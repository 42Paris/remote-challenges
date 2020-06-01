/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 18:19:08 by kibotrel          #+#    #+#             */
/*   Updated: 2020/06/01 22:22:20 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

uint8_t	secure_stack(t_env *env, uint8_t i, t_cell cell)
{
	uint8_t	index;

	index = 0;
	while (env->stack[index].y < 10)
	{
		if (env->stack[index].y == cell.y && env->stack[index].x == cell.x)
			return (i);
		index++;
	}
	env->stack[i] = cell;
	return (i + 1);
}

uint8_t	secure_stack2(t_cell stack[100], uint8_t i, t_cell cell)
{
	uint8_t	index;

	index = 0;
	while (stack[index].y < 10)
	{
		if (stack[index].y == cell.y && stack[index].x == cell.x)
			return (i);
		index++;
	}
	stack[i] = cell;
	return (i + 1);
}

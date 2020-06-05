/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:20:31 by kibotrel          #+#    #+#             */
/*   Updated: 2020/06/01 21:59:07 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "structs.h"

uint8_t	stack_index(t_env *env)
{
	uint8_t	i;

	i = 0;
	while (env->stack[i].y < 10)
		i++;
	return (i);
}

uint8_t	stack_index2(t_cell stack[100])
{
	uint8_t	i;

	i = 0;
	while (stack[i].y < 10)
		i++;
	return (i);
}

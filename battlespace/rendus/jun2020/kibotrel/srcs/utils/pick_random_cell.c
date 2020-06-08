/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pick_random_cell.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 05:44:00 by kibotrel          #+#    #+#             */
/*   Updated: 2020/06/01 22:21:54 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "utils.h"

t_cell	pick_random_cell(t_env *env)
{
	uint8_t	number;

	number = env->spots[rand() % env->remaining_shots];
	update_remaining_shots(env, number);
	return ((t_cell){number / 10, number % 10});
}

t_cell	pick_random_shield(t_area *area)
{
	uint8_t	number;

	number = area->spots[rand() % area->remaining_shots];
	update_remaining_shots2(area, number);
	return ((t_cell){number / 10, number % 10});
}

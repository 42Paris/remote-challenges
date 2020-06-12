/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_remaining_shots.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 05:48:03 by kibotrel          #+#    #+#             */
/*   Updated: 2020/06/01 22:01:01 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "structs.h"

void	update_remaining_shots(t_env *env, uint8_t excluded)
{
	uint8_t	i;
	uint8_t j;
	uint8_t *remaining;

	i = 0;
	j = 0;
	env->remaining_shots--;
	remaining = malloc(sizeof(uint8_t) * env->remaining_shots);
	while (i <= env->remaining_shots)
	{
		if (env->spots[i] == excluded)
		{
			i++;
			continue;
		}
		remaining[j++] = env->spots[i];
		i++;
	}
	free(env->spots);
	env->spots = remaining;
}

void	update_remaining_shots2(t_area *area, uint8_t excluded)
{
	uint8_t	i;
	uint8_t j;
	uint8_t *remaining;

	i = 0;
	j = 0;
	area->remaining_shots--;
	remaining = malloc(sizeof(uint8_t) * area->remaining_shots);
	while (i <= area->remaining_shots)
	{
		if (area->spots[i] == excluded)
		{
			i++;
			continue;
		}
		remaining[j++] = area->spots[i];
		i++;
	}
	free(area->spots);
	area->spots = remaining;
}

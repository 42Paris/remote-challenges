/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   communication.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 03:56:18 by kibotrel          #+#    #+#             */
/*   Updated: 2020/06/01 21:57:16 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "core.h"
#include "utils.h"

void	fire_on(t_cell cell, char *response)
{
	char	request[4];
	uint8_t	size;

	request[0] = 'A' + cell.y;
	request[1] = '0' + cell.x;
	request[2] = '\n';
	request[3] = '\0';
	write(1, request, 3);
	size = read(0, response, 8);
	response[size] = '\0';
}

void	handle_response(t_env *env, char *response, t_cell cell)
{
	uint8_t	state;

	state = 0;
	if (!ft_strcmp(response, "MISS\n"))
		state = 1;
	else if (!ft_strcmp(response, "HIT\n"))
	{
		state = 2;
		env->mode = 1;
		update_stack(env, cell);
	}
	else if (!ft_strcmp(response, "SUNK\n"))
		state = shield_or_ship(env);
	else if (!ft_strcmp(response, "BLOCKED\n"))
	{
		destroy_shield(env, cell);
		env->protected = 0;
		return ;
	}
	update_grid(env, cell, state);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 02:54:25 by kibotrel          #+#    #+#             */
/*   Updated: 2020/06/01 21:47:08 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core.h"
#include "setup.h"
#include "utils.h"

int			main(void)
{
	char	response[9];
	t_env	env;
	t_cell	cell;

	if (!setup(&env))
		return (0);
	while (env.ships > 0)
	{
		ft_bzero(response, sizeof(char) * 9);
		cell = (!env.mode ? pick_random_cell(&env) : target_mode(&env));
		fire_on(cell, response);
		handle_response(&env, response, cell);
	}
	return (0);
}

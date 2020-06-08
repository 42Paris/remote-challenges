/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 03:55:35 by kibotrel          #+#    #+#             */
/*   Updated: 2020/06/01 22:14:31 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CORE_H
# define CORE_H

# include "structs.h"

void	fire_on(t_cell cell, char *response);
void	update_stack(t_env *env, t_cell cell);
void	destroy_shield(t_env *env, t_cell cell);
void	update_grid(t_env *env, t_cell cell, uint8_t state);
void	handle_response(t_env *env, char *response, t_cell cell);
void	update_stack2(t_env *env, t_cell stack[100], t_cell cell);
void	predict_future(t_env *env, t_cell cell);
void	find_sunk(t_env *env, t_cell stack[100]);
void	optimize_grid(t_env *env, t_cell stack[100]);

t_cell	target_mode(t_env *env);
uint8_t	shield_or_ship(t_env *env);

#endif

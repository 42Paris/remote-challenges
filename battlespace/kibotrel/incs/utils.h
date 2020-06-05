/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 02:56:39 by kibotrel          #+#    #+#             */
/*   Updated: 2020/06/01 21:39:45 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdint.h>
# include "structs.h"

void	ft_bzero(void *memory, uint32_t size);
void	clear_2d_array(uint32_t array[10][10]);
void	update_remaining_shots(t_env *env, uint8_t excluded);
void	update_remaining_shots2(t_area *area, uint8_t excluded);
t_cell	pick_random_cell(t_env *env);
t_cell	pick_random_shield(t_area *area);
uint8_t	stack_index(t_env *env);
uint8_t	stack_index2(t_cell stack[100]);
uint8_t	area_2d(t_cell min, t_cell max);
uint8_t	ft_strcmp(const char *s1, const char *s2);
uint8_t	secure_stack(t_env *env, uint8_t i, t_cell cell);
uint8_t	secure_stack2(t_cell stack[100], uint8_t i, t_cell cell);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 02:56:48 by kibotrel          #+#    #+#             */
/*   Updated: 2020/06/01 21:39:16 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdint.h>

typedef struct	s_cell
{
	uint32_t	y;
	uint32_t	x;
}				t_cell;

typedef struct	s_area
{
	t_cell		min;
	t_cell		max;
	t_cell		current;
	uint8_t		*spots;
	uint8_t		remaining_shots;
}				t_area;

typedef struct	s_env
{
	t_cell		stack[100];
	uint8_t		mode;
	uint8_t		protected;
	uint8_t		ships;
	uint8_t		*spots;
	uint8_t		remaining_shots;
	uint32_t	grid[10][10];
}				t_env;

#endif

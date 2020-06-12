/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btsp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 08:09:19 by hben-yah          #+#    #+#             */
/*   Updated: 2020/06/02 19:09:28 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTSP_H
# define BTSP_H

# include <sys/time.h>
# include "libft.h"

/*
** Structures
*/

enum					e_state
{
	UNKNOW,
	MISS,
	HIT,
	SUNK,
	BLOCKED
};

enum					e_army
{
	NATION,
	MERCENARIES,
	ALIENS
};

enum					e_strategy
{
	RANDOM_ATTACK,
	SHIP_ATTACK,
	SHIELD_GEN_TRACKING
};

typedef struct			s_point
{
	int		x;
	int		y;
}						t_point;

typedef struct			s_ship
{
	int				id;
	enum e_army		army;
	int				no;
	int				width;
	int				height;
	int				model[10][10];
}						t_ship;

typedef struct			s_btsp
{
	int				turn;
	enum e_state	map[12][12];
	int				heat[12][12];
	t_point			target_coord;
	int				shield;
	enum e_strategy	strategy;
	int				last_sunken_ship_size;
	int				last_sunken_ship_y;
	int				last_sunken_ship_x;
	int				last_compared_size;
	int				attachment;
	int				conc_army[3];
	int				conc_ship[15];
}						t_btsp;

extern const t_ship		g_ships[];

/*
** Prototypes
*/

void					analyse_sunken_ship(t_btsp *btsp);
int						compare_sunken_ship_to_database(t_btsp *btsp,
															t_ship *ship);
int						is_ship_concording(t_btsp *btsp, t_ship *ship, int y,
																		int x);
void					rotate_ship(t_ship *ship);
int						is_sunken_element_shield_generator(t_btsp *btsp, int y,
																		int x);
int						ft_getc(void);
void					generate_shield_heat_map(t_btsp *btsp);
void					fill_shield_heat_map(t_btsp *btsp, int val, int y,
																		int x);
void					generate_heat_map(t_btsp *btsp);
void					init_btsp(t_btsp *btsp);
void					init_map(t_btsp *btsp);
int						main(void);
void					generate_ship_heat_map(t_btsp *btsp);
void					compute_ships_heat_map(t_btsp *btsp, t_ship *ship);
int						is_ship_compatible(t_btsp *btsp, t_ship *ship, int y,
																		int x);
int						is_hit_or_blocked(t_btsp *btsp, int y, int x);
void					fill_ship_heat_map(t_btsp *btsp, t_ship *ship, int y,
																		int x);
void					assess_outcome(t_btsp *btsp);
void					sunk_ship(t_btsp *btsp);
void					clear_sunked_ship(t_btsp *btsp, int y, int x);
void					launch_attack(t_btsp *btsp);
void					select_target_coord(t_btsp *btsp);
int						look_for_blocked_coordinates(t_btsp *btsp);
void					select_best_coordinates(t_btsp *btsp);
void					select_random_coordinates(t_btsp *btsp);

#endif

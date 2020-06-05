/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btsp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 12:45:43 by memartin          #+#    #+#             */
/*   Updated: 2020/06/01 12:51:38 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTSP_H
# define BTSP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <sys/time.h>
# include "../libft/libft.h"

typedef struct	s_data
{
	int			**map;
	int			**weight;
	int			**shield;
	int			nb_hit;
	int			hit[7];

	char		move[4];
	char		res;
	int			highest_prob;
	int			nb_prob;

	int			b_shield;
	int			s_sunk;
	int			nb_ship_down;
}				t_data;

typedef struct	s_weight_data
{
	int			xmin;
	int			xmax;
	int			ymin;
	int			ymax;
	int			max_res;
}				t_weight_data;

int				**init_grid(int nb);
void			reset_shield_grid(t_data *d);
int				get_rand(int max);
int				nb_possible_shield(int **map);
void			set_move_shield(t_data *d, int count);
void			set_move(t_data *d, int count, int nb);
void			start_chase(t_data *d);
void			print_read(t_data *d);
void			pre_destruction(t_data *d, int x, int y);
void			destruction(t_data *d, int x, int y);
void			set_weight(t_data *d);
void			set_highest_prob(t_data *d);
void			reset_hit(t_data *d);
void			get_shield(t_data *d);
void			set_suffix_move(t_data *d);
void			clean_around(t_data *d, int x, int y);
void			top_destruction(t_data *d, int x, int y);
void			top_right_destruction(t_data *d, int x, int y);
void			top_left_destruction(t_data *d, int x, int y);
void			right_destruction(t_data *d, int x, int y);
void			left_destruction(t_data *d, int x, int y);
void			bottom_destruction(t_data *d, int x, int y);
void			bottom_right_destruction(t_data *d, int x, int y);
void			bottom_left_destruction(t_data *d, int x, int y);

#endif

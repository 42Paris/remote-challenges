/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btsp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 15:53:17 by mchardin          #+#    #+#             */
/*   Updated: 2020/06/02 23:02:57 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTSP_H

# define BTSP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

typedef enum	e_box
{
	UNKNOWN,
	KNOWN,
	HIT,
	HIT_TMP,
	SUNK,
	SHIELD,
	MINE,
	PROB_EMPTY,
	EMPTY,
	BLOCKED
}				t_box;

typedef enum	e_line
{
	VERTICAL,
	HORIZONTAL
}				t_line;

typedef enum	e_around
{
	TO,
	BO,
	LE,
	RI,
	TO_LE,
	BO_LE,
	TO_RI,
	BO_RI
}				t_around;

typedef struct	s_idx
{
	int			i;
	int			j;
}				t_idx;

typedef struct	s_ship
{
	t_line		dir;
	int			len;
	int			size;
	t_idx		line;
}				t_ship;

typedef struct	s_btsp
{
	t_box		map[10][10];
	int			rounds;
	int			found_shield;
	t_idx		ship[6];
	t_idx		last_hit;
	int			alien;
}				t_btsp;

t_box			box_return(void);
t_box			one_move(t_btsp *btsp, t_idx idx);
int				move_n_solve(t_btsp *btsp, int row, int column,
				int (*ft_solve)(t_btsp *, t_idx, t_box));
int				check_later(t_btsp btsp, int i, int j);
int				four_moves(t_btsp *btsp, t_idx idx, t_box box,
				int (*ft_solve)(t_btsp *, t_idx, t_box));
int				fill_all(t_btsp *btsp, t_box box, int rev,
				int (*ft_solve)(t_btsp *, t_idx, t_box));
int				count_around(t_btsp btsp, t_idx idx, t_box box);
t_idx			step_to(t_btsp *btsp, t_idx idx, t_box box, int skip);
t_idx			find_box(t_btsp btsp, t_box box);
int				count_boxes(t_btsp btsp, t_box box);
int				search_around(t_btsp *btsp);
int				solve_ship(t_btsp *btsp, t_idx idx);
int				ft_solve(t_btsp *btsp, t_idx idx, t_box box);
int				solve_sunk(t_btsp *btsp, t_idx idx);
void			box_replace(t_btsp *btsp, int i, int j);
int				sunken_ship(t_btsp *btsp, int i, int j);
int				ship_has_sunk(t_btsp *btsp, t_idx idx);
int				is_in_map(int i, int j);
int				is_box(t_btsp btsp, int i, int j, t_box box);
t_idx			add_to_idx(t_idx idx, int i_add, int j_add);
int				is_on_ship(t_idx *ship, t_idx idx);
int				next_solve(t_btsp *btsp, t_idx next);
int				is_mine(t_btsp *btsp, t_idx idx);
int				longest_line(t_idx lines[10], t_line *dir);
t_idx			find_line(t_idx ship[5], t_line *dir, int *len, int *size);
int				fill_line(t_btsp *btsp, t_line dir, t_idx line);
int				try_patterns(t_btsp *btsp);
int				three_pattern(t_btsp *btsp, t_ship *ship);
t_idx			ret_around(t_idx box, t_around around, t_line dir);
t_idx			square_pattern(t_btsp *btsp, t_ship *ship, t_box box, int skip);
t_idx			xy_pattern(t_btsp *btsp, t_ship *ship, t_box box, int skip);
t_idx			diag_pattern(t_btsp *btsp, t_ship *ship, t_box box, int skip);
t_idx			triple_pattern(t_btsp *btsp, t_ship *ship, t_box box, int skip);

#endif

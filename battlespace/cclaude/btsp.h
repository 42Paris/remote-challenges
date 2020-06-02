/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btsp.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cclaude <cclaude@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 19:47:16 by cclaude           #+#    #+#             */
/*   Updated: 2020/06/02 12:25:22 by cclaude          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTSP_H
# define BTSP_H

# include <unistd.h>

# define MISS 0
# define HIT 1
# define SUNK 2
# define BLOCKED 3

void	fill_map(char map[10][10]);
int		orientation(char map[10][10]);

void	map_coeff(char map[10][10], int pdf[10][10]);
void	find_target(char map[10][10], int pdf[10][10], int *i, int *j);

int		check_spot(char *marks, char map[10][10], int i, int j);
int		check_line(char mp[10][10], int i, int j);

int		sink_boat(char map[10][10], int i, int j);

int		shoot(int i, int j);

void	mark_sunk(char map[10][10], int i, int j);

int		possible_shields(char map[10][10]);
void	target_shield(char map[10][10], int pdf[10][10]);
int		got_shield(char map[10][10], int i, int j);
void	clear_blocked(char map[10][10]);

int		ft_abs(int n);
int		ft_strchr(const char *s, int c);
int		ft_strcmp(const char *s1, const char *s2);

#endif

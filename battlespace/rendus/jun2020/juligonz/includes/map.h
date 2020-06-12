/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:43:03 by juligonz          #+#    #+#             */
/*   Updated: 2020/06/02 15:40:53 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct	s_map
{
	int		size;
	size_t	nb_cells;
	char	*grid;
}				t_map;

t_map			create_map(int size);
t_map			*malloc_map(int size);
void			destroy_map(t_map to_destroy);
void			free_map(t_map *to_free);

char			get_cell(int column, int row);
void			set_cell(int column, int row, char value);

void			print_map();
void			print_position(int column, int row);

#endif

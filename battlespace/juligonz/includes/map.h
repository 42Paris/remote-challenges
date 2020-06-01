/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:43:03 by juligonz          #+#    #+#             */
/*   Updated: 2020/06/01 18:36:19 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct	s_map
{
	int		size;
	char	*grid;
}				t_map;

t_map			create_map(int size);
t_map			*malloc_map(int size);
void			destroy_map(t_map to_destroy);
void			free_map(t_map *to_free);

char			get_cell(int row, int column);
char			get_cell(int row, int column);
char			set_cell(int row, int column, char value);
			
void			print_map();

#endif
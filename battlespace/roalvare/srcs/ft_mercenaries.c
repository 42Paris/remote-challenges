/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mercenaries.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 20:52:42 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/28 21:58:49 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

t_box	*create_station()
{
	t_box *station;

	station = create_destroyer();
	add_box(station, LEFT);
	add_box(station, RIGHT);
	return (station);
}

t_box	*create_square()
{
	t_box	*square;
	t_box	*tmp;

	square = create_fregate();
	tmp = square->near[UP];
	add_box(square, RIGHT);
	square = square->near[RIGHT];
	add_box(square, UP);
	square = square->near[UP];
	add_link(square, tmp, LEFT);
	return (square);
}

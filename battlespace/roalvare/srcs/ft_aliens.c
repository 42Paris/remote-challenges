/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aliens.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 22:02:45 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/28 22:27:12 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

t_box	*create_mother_ship()
{
	t_box *mother_ship;

	mother_ship = create_destroyer();
	mother_ship = mother_ship->near[DOWN];
	add_box(mother_ship, DOWN_LEFT);
	add_box(mother_ship, DOWN_RIGHT);
	return (mother_ship);
}

t_box	*create_hole()
{
	t_box	*hole;
	t_box	*tmp;

	hole = create_box();
	tmp = hole;
	add_box(hole, DOWN_RIGHT);
	hole = hole->near[DOWN_RIGHT];
	add_box(hole, UP_RIGHT);
	hole = hole->near[UP_RIGHT];
	add_box(hole, UP_LEFT);
	hole = hole->near[UP_LEFT];
	add_link(hole, tmp, DOWN_LEFT);
	return (hole);
}

t_box	*create_blocker()
{
	t_box	*blocker;

	blocker = create_box();
	add_box(blocker, UP_RIGHT);
	blocker = blocker->near[UP_RIGHT];
	add_box(blocker, UP_RIGHT);
	return (blocker);
}

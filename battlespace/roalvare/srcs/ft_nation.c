/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 12:59:26 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/28 20:48:28 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_box	*create_fregate()
{
	t_box *fregate;

	fregate = create_box();
	add_box(fregate, UP);
	return (fregate);
}

t_box	*create_destroyer()
{
	t_box *destroyer;

	destroyer = create_fregate();
	add_box(destroyer, DOWN);
	return (destroyer);
}

t_box	*create_cruiser()
{
	t_box *cruiser;

	cruiser = create_destroyer();
	cruiser = cruiser->near[DOWN];
	add_box(cruiser, DOWN);
	return (cruiser);
}

t_box	*create_carrier()
{
	t_box *carrier;

	carrier = create_cruiser();
	carrier = carrier->near[DOWN];
	add_box(carrier, DOWN);
	return (carrier);
}

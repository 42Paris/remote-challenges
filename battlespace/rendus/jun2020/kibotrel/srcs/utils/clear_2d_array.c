/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_2d_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 03:10:58 by kibotrel          #+#    #+#             */
/*   Updated: 2020/06/01 01:23:43 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	clear_2d_array(uint32_t array[10][10])
{
	uint32_t	row;
	uint32_t	column;

	row = 0;
	while (row < 10)
	{
		column = 0;
		while (column < 10)
			ft_bzero(&array[row][column++], sizeof(uint32_t));
		row++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 16:20:31 by hben-yah          #+#    #+#             */
/*   Updated: 2020/06/02 18:48:42 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

void	launch_attack(t_btsp *btsp)
{
	ft_putchar(btsp->target_coord.y - 1 + 'A');
	ft_putchar(btsp->target_coord.x - 1 + '0');
	ft_putchar('\n');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linear_interpolate.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 11:53:14 by hben-yah          #+#    #+#             */
/*   Updated: 2018/05/25 20:42:06 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_lininterp(int p1, int p2, double ratio)
{
	return ((int)((double)p1 * (1.0 - ratio) + (double)p2 * ratio));
}

double	ft_rlininterp(double px, double p1, double p2)
{
	if (px == p1)
		return (0.0);
	else if (px == p2)
		return (1.0);
	return ((px - p1) / (p2 - p1));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:53:07 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:18:50 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	convert_color(t_printf *pf, t_formatter *fmt, int light)
{
	int			color;
	t_conv		c;

	ft_bzero(&c, sizeof(t_buffer));
	color = fmt->width;
	color %= 7;
	if (color > 0)
		color += 30;
	pf->len += put((light ? "\e[1;" : "\e[0;"), 4);
	itoa_base(&c, color, 10, 0);
	pf->len += put(c.conv.buff, c.conv.len);
	pf->len += put("m", 1);
	fmt->width = 0;
	return (0);
}

int	convert_q(t_printf *pf, t_formatter *fmt, va_list ap)
{
	(void)ap;
	return (convert_color(pf, fmt, 0));
}

int	convert_q_up(t_printf *pf, t_formatter *fmt, va_list ap)
{
	(void)ap;
	return (convert_color(pf, fmt, 1));
}

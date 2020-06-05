/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:14:57 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/25 10:41:06 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		conv_c(va_list args, t_manager *p)
{
	int		wc;
	char	c;

	wc = cast_c(p, args);
	if (p->f.l && wc > 255)
	{
		p->is_error = 1;
		return ;
	}
	c = (char)wc;
	if (!p->f.dash)
		while (--p->width > 0)
			write_buffer(p, " ", 1);
	write_buffer(p, &c, 1);
	if (p->f.dash)
		while (--p->width > 0)
			write_buffer(p, " ", 1);
}

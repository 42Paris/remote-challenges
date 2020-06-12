/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 15:47:21 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:19:09 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		convert_p(t_printf *pf, t_formatter *fmt, va_list ap)
{
	t_conv		c;
	int			before;
	int			zero;

	ft_bzero(&c, sizeof(t_conv));
	fmt->length = 3 << ft_indexof('l', LENGTHS);
	bwrite(&c.prefix, "0x", 2);
	unsigned_integer(fmt, &c, ap, 16);
	fill_precision(&c, fmt);
	fill_width(&c, fmt);
	if ((zero = (is_flag('0', *fmt) && fmt->precision < 1)))
		pf->len += put(c.prefix.buff, c.prefix.len);
	if ((before = !is_flag('-', *fmt)))
		pf->len += put(c.width.buff, c.width.len);
	if (!zero)
		pf->len += put(c.prefix.buff, c.prefix.len);
	pf->len += put(c.prec.buff, c.prec.len);
	pf->len += put(c.conv.buff, c.conv.len);
	if (!before)
		pf->len += put(c.width.buff, c.width.len);
	return (pf->len);
}

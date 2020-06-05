/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:41:46 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:18:57 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		convert_di(t_printf *pf, t_formatter *fmt, va_list ap)
{
	t_conv		c;
	int			before;
	int			zero;

	ft_bzero(&c, sizeof(t_conv));
	signed_integer(fmt, &c, ap, 10);
	fill_precision(&c, fmt);
	fill_width(&c, fmt);
	if (c.sign && (zero = (is_flag('0', *fmt) && fmt->precision < 1)))
		pf->len += put(&c.sign, 1);
	if ((before = !is_flag('-', *fmt)))
		pf->len += put(c.width.buff, c.width.len);
	if (c.sign && !zero)
		pf->len += put(&c.sign, 1);
	pf->len += put(c.prec.buff, c.prec.len);
	pf->len += put(c.conv.buff, c.conv.len);
	if (!before)
		pf->len += put(c.width.buff, c.width.len);
	return (pf->len);
}

int		convert_u(t_printf *pf, t_formatter *fmt, va_list ap)
{
	t_conv		c;
	int			before;

	ft_bzero(&c, sizeof(t_conv));
	unsigned_integer(fmt, &c, ap, 10);
	fill_precision(&c, fmt);
	fill_width(&c, fmt);
	if ((before = !is_flag('-', *fmt)))
		pf->len += put(c.width.buff, c.width.len);
	pf->len += put(c.prec.buff, c.prec.len);
	pf->len += put(c.conv.buff, c.conv.len);
	if (!before)
		pf->len += put(c.width.buff, c.width.len);
	return (pf->len);
}

int		convert_x(t_printf *pf, t_formatter *fmt, va_list ap)
{
	t_conv		c;
	int			before;
	int			zero;

	ft_bzero(&c, sizeof(t_conv));
	if (is_flag('#', *fmt))
	{
		if (fmt->converter == 'X')
			bwrite(&c.prefix, "0X", 2);
		else
			bwrite(&c.prefix, "0x", 2);
	}
	unsigned_integer(fmt, &c, ap, 16);
	fill_precision(&c, fmt);
	fill_width(&c, fmt);
	if ((zero = (is_flag('0', *fmt) && fmt->precision < 1)))
		pf->len += put(c.prefix.buff, c.prefix.len);
	if ((before = !is_flag('-', *fmt)))
		pf->len += put(c.width.buff, c.width.len);
	if (!zero)
		pf->len += put(c.prefix.buff, c.prefix.len);
	pf->len += put(c.prec.buff, c.prec.len) + put(c.conv.buff, c.conv.len);
	if (!before)
		pf->len += put(c.width.buff, c.width.len);
	return (pf->len);
}

int		convert_o(t_printf *pf, t_formatter *fmt, va_list ap)
{
	t_conv		c;
	int			alt;
	int			before;

	ft_bzero(&c, sizeof(t_conv));
	if ((alt = is_flag('#', *fmt)))
		bwrite(&c.conv, "0", 1);
	fmt->converter = 'o';
	unsigned_integer(fmt, &c, ap, 8);
	fill_precision(&c, fmt);
	fill_width(&c, fmt);
	if ((before = !is_flag('-', *fmt)))
		pf->len += put(c.width.buff, c.width.len);
	pf->len += put(c.prec.buff, c.prec.len);
	pf->len += put(c.conv.buff, c.conv.len);
	if (!before)
		pf->len += put(c.width.buff, c.width.len);
	return (pf->len);
}

int		convert_b(t_printf *pf, t_formatter *fmt, va_list ap)
{
	t_conv		c;
	int			before;

	ft_bzero(&c, sizeof(t_conv));
	if (is_flag('#', *fmt))
		bwrite(&c.conv, "bf", 1);
	unsigned_integer(fmt, &c, ap, 2);
	fill_precision(&c, fmt);
	fill_width(&c, fmt);
	if ((before = !is_flag('-', *fmt)))
		pf->len += put(c.width.buff, c.width.len);
	pf->len += put(c.prec.buff, c.prec.len);
	pf->len += put(c.conv.buff, c.conv.len);
	if (!before)
		pf->len += put(c.width.buff, c.width.len);
	return (pf->len);
}

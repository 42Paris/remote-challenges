/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 11:36:00 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:18:55 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void	compute_f(t_double *d)
{
	unsigned char	tmp[10000];
	unsigned long	mask;
	int				i;

	mask = 1;
	mask <<= 62;
	i = 1;
	d->buff[4999] = 1;
	while (mask)
	{
		if (d->mant & mask)
		{
			ft_bzero(tmp, sizeof(tmp));
			tmp[4999] = 1;
			str_power(tmp, 5, i, sizeof(tmp));
			str_add(d->buff + i, tmp, sizeof(d->buff) - i - 1);
		}
		mask >>= 1;
		++i;
	}
	str_power(d->buff, 2, d->expo, sizeof(tmp));
	d->beg = 0;
	while (d->buff[d->beg] == 0 && d->beg < 4999)
		++d->beg;
}

void	fill_dbl(t_double *d)
{
	d->sign = d->m[9] & 128 ? 1 : 0;
	d->expo = d->m[9] & 127;
	d->expo = (d->expo << 8) + d->m[8];
	d->expo = d->expo - 16383;
	d->mant = d->m[7];
	d->mant = (d->mant << 8) + d->m[6];
	d->mant = (d->mant << 8) + d->m[5];
	d->mant = (d->mant << 8) + d->m[4];
	d->mant = (d->mant << 8) + d->m[3];
	d->mant = (d->mant << 8) + d->m[2];
	d->mant = (d->mant << 8) + d->m[1];
	d->mant = (d->mant << 8) + d->m[0];
}

int		convert_f(t_printf *pf, t_formatter *fmt, va_list ap)
{
	long double	arg;
	t_double	d;

	if (is_length('L', *fmt, 1) == 128)
		arg = va_arg(ap, long double);
	else
		arg = va_arg(ap, double);
	if (arg == 0 && fmt->precision <= -1)
	{
		pf->len += put("0.000000", 8);
		return (0);
	}
	if (arg != arg || arg == 1.0 / 0.0)
	{
		pf->len += put(arg == 1.0 / 0.0 ? "INF" : "NAN", 3);
		return (0);
	}
	d.m = (unsigned char *)&arg;
	fill_dbl(&d);
	ft_bzero(d.buff, sizeof(d.buff));
	compute_f(&d);
	return (write_double(pf, fmt, &d));
}

void	write_conv(t_conv *c, t_double *d, t_formatter *fmt)
{
	int i;

	i = fmt->precision;
	if (d->buff[5000 + i] > 4)
	{
		d->buff[5000 + i - 1] += 1;
		while (d->buff[5000 + i - 1] > 9)
		{
			d->buff[5000 + i - 1] = 0;
			d->buff[5000 + i - 2] += 1;
			--i;
		}
	}
	dblwrite(&c->conv, d->buff + d->beg, 5000 - d->beg);
	if (fmt->precision > 0 || is_flag('#', *fmt))
		bwrite(&c->conv, ".", 1);
	dblwrite(&c->conv, d->buff + 5000, fmt->precision);
	fill_width(c, fmt);
}

int		write_double(t_printf *pf, t_formatter *fmt, t_double *d)
{
	t_conv		c;
	int			zero;
	int			before;

	ft_bzero(&c, sizeof(t_conv));
	c.dbl = 1;
	if (d->sign)
		c.sign = '-';
	else if (is_flag('+', *fmt))
		c.sign = '+';
	else if (is_flag(' ', *fmt))
		c.sign = ' ';
	if (fmt->precision == -1)
		fmt->precision = 6;
	write_conv(&c, d, fmt);
	if (c.sign && (zero = (is_flag('0', *fmt))))
		pf->len += put(&c.sign, 1);
	if ((before = !is_flag('-', *fmt)))
		pf->len += put(c.width.buff, c.width.len);
	if (c.sign && !zero)
		pf->len += put(&c.sign, 1);
	pf->len += put(c.conv.buff, c.conv.len);
	if (!before)
		pf->len += put(c.width.buff, c.width.len);
	return (pf->len);
}

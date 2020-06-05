/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_unsigned.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:16:18 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:19:03 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	uitoa_base(t_conv *c, intmax_t i, int b, char upcase)
{
	const char		*a = (upcase ? "0123456789ABCDEF" : "0123456789abcdef");
	const uintmax_t	ui = (uintmax_t)i;
	int				ret;

	ret = 1;
	if ((uintmax_t)b <= ui)
		ret += uitoa_base(c, (intmax_t)(ui / b), b, upcase);
	bwrite(&c->conv, a + (size_t)(ui % b), 1);
	return (ret);
}

static uintmax_t
	get_arg(va_list ap, t_formatter *fmt)
{
	uintmax_t	arg;

	if (is_length('h', *fmt, 3) == 3)
		arg = (unsigned char)va_arg(ap, unsigned);
	else if (is_length('h', *fmt, 1) == 1)
		arg = (unsigned short)va_arg(ap, unsigned);
	else if (is_length('l', *fmt, 1) == 4)
		arg = va_arg(ap, unsigned long);
	else if (is_length('l', *fmt, 3) == 12)
		arg = va_arg(ap, unsigned long long);
	else if (is_length('j', *fmt, 1) == 16)
		arg = va_arg(ap, uintmax_t);
	else if (is_length('t', *fmt, 1) == 32)
		arg = va_arg(ap, size_t);
	else if (is_length('z', *fmt, 1) == 64)
		arg = va_arg(ap, size_t);
	else
		arg = va_arg(ap, unsigned);
	return (arg);
}

int	unsigned_integer(t_formatter *fmt, t_conv *c, va_list ap, int b)
{
	uintmax_t	arg;
	int			ret;

	arg = get_arg(ap, fmt);
	if (arg == 0 && is_flag('#', *fmt)
		&& (fmt->converter == 'x' || fmt->converter == 'X'))
		c->prefix.len -= 2;
	if ((arg == 0 && fmt->precision == 0) ||
	(arg == 0 && fmt->converter == 'o' && is_flag('#', *fmt)))
		return (0);
	ret = uitoa_base(c, arg, ft_abs(b), ft_isupper(fmt->converter));
	if (b == 10 && is_flag('\'', *fmt))
		ret += set_coma(c, ret);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_signed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 15:16:35 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:19:01 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	itoa_base(t_conv *c, intmax_t i, int base, char upcase)
{
	const char	*a = (upcase ? "0123456789ABCDEF" : "0123456789abcdef");
	int			ret;

	ret = 1;
	if (i <= -base || base <= i)
		ret += itoa_base(c, i / base, base, upcase);
	bwrite(&c->conv, a + ft_abs(i % base), 1);
	return (ret);
}

static intmax_t
	get_arg(va_list ap, t_formatter *fmt)
{
	intmax_t	arg;

	if (is_length('h', *fmt, 3) == 3)
		arg = (char)va_arg(ap, int);
	else if (is_length('h', *fmt, 1) == 1)
		arg = (short)va_arg(ap, int);
	else if (is_length('l', *fmt, 1) == 4)
		arg = va_arg(ap, long);
	else if (is_length('l', *fmt, 3) == 12)
		arg = va_arg(ap, long long);
	else if (is_length('j', *fmt, 1) == 16)
		arg = va_arg(ap, intmax_t);
	else if (is_length('t', *fmt, 1) == 32)
		arg = va_arg(ap, ptrdiff_t);
	else if (is_length('z', *fmt, 1) == 64)
		arg = va_arg(ap, long);
	else
		arg = va_arg(ap, int);
	return (arg);
}

int	signed_integer(t_formatter *fmt, t_conv *c, va_list ap, int b)
{
	intmax_t	arg;

	arg = get_arg(ap, fmt);
	if (arg < 0)
		c->sign = '-';
	else if (is_flag('+', *fmt))
		c->sign = '+';
	else if (is_flag(' ', *fmt))
		c->sign = ' ';
	if (arg == 0 && fmt->precision == 0)
		return (0);
	itoa_base(c, arg, ft_abs(b), ft_isupper(fmt->converter));
	if (b == 10 && is_flag('\'', *fmt))
		set_coma(c, c->conv.len);
	return (1);
}

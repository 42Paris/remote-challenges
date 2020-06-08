/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:31:26 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:18:59 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		convert_n(t_printf *pf, t_formatter *fmt, va_list ap)
{
	void	*arg;

	if (!(arg = va_arg(ap, void *)))
		return (0);
	fmt->precision = -1;
	fmt->width = 0;
	if (is_length('h', *fmt, 3) == 3)
		*(char *)arg = (char)(pf->len + fmt->prev_len);
	else if (is_length('h', *fmt, 1) == 1)
		*(short *)arg = (short)(pf->len + fmt->prev_len);
	else if (is_length('l', *fmt, 1) == 4)
		*(long *)arg = (long)(pf->len + fmt->prev_len);
	else if (is_length('l', *fmt, 3) == 12)
		*(long long *)arg = (long long)(pf->len + fmt->prev_len);
	else if (is_length('j', *fmt, 1) == 16)
		*(intmax_t *)arg = (intmax_t)(pf->len + fmt->prev_len);
	else if (is_length('t', *fmt, 1) == 32)
		*(ptrdiff_t *)arg = (ptrdiff_t)(pf->len + fmt->prev_len);
	else if (is_length('z', *fmt, 1) == 64)
		*(long *)arg = (long)(pf->len + fmt->prev_len);
	else
		*(int *)arg = (int)(pf->len + fmt->prev_len);
	return (0);
}

int		set_coma(t_conv *c, int len)
{
	t_conv		tmp;
	int			i;

	ft_bzero(&tmp, sizeof(t_conv));
	i = 0;
	while (len-- && c->conv.len
		&& ft_isdigit(*(c->conv.buff + c->conv.len - 1)))
	{
		bwrite(&tmp.conv, c->conv.buff + --c->conv.len, 1);
		if (++i % 3 == 0 && len)
			bwrite(&tmp.conv, ",", 1);
	}
	while (tmp.conv.len)
		bwrite(&c->conv, tmp.conv.buff + --tmp.conv.len, 1);
	tmp.conv.len = 0;
	return (i / 3);
}

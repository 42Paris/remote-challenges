/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 11:25:58 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:18:41 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int
	convertion(t_printf *pf, t_formatter *fmt)
{
	const void	*f[] = {
		&convert_di, &convert_di, &convert_di, &convert_o, &convert_o,
		&convert_u, &convert_u, &convert_x, &convert_x, &convert_char,
		&convert_wchar, &convert_str, &convert_wstr, &convert_p, &convert_b,
		&convert_n, &convert_q, &convert_q_up, &convert_k, &convert_m,
		&convert_r, &convert_f};
	int			conv_id;

	if (ft_indexof(fmt->converter, LONG_NUMERICS) > -1)
		fmt->length = 1 << ft_indexof('l', LENGTHS);
	if ((conv_id = ft_indexof(fmt->converter, CONVERTERS)) <= -1)
		return (convert_const(pf, fmt));
	return (((int (*)())f[conv_id])(pf, fmt, fmt->pos ? pf->args.selected
														: pf->args.natural));
}

int
	fill_precision(t_conv *c, t_formatter *fmt)
{
	int len;

	len = c->conv.len;
	if (len < fmt->precision && ft_indexof(fmt->converter, NUMERICS) > -1)
	{
		while (len < fmt->precision && ++len)
			bwrite(&c->prec, "0", 1);
	}
	return (len);
}

void
	fill_width(t_conv *c, t_formatter *fmt)
{
	int		len;
	char	pad;

	if (c->dbl)
		len = c->conv.len + (c->sign > 0);
	else
		len = c->conv.len + c->prec.len + c->prefix.len + (c->sign > 0);
	if (len <= fmt->width)
	{
		if (is_flag('0', *fmt)
			&& !is_flag('-', *fmt) && (fmt->precision <= -1 || c->dbl))
			pad = '0';
		else
			pad = ' ';
		while (len < fmt->width && ++len)
		{
			bwrite(&c->width, &pad, 1);
		}
	}
}

void
	fill_width_chr(t_printf *pf, t_formatter *fmt, int conv_ret)
{
	int		len;
	char	pad;

	len = conv_ret;
	if (len <= fmt->width && conv_ret != -1)
	{
		if (is_flag('0', *fmt) && !is_flag('-', *fmt) && fmt->precision <= -1)
			pad = '0';
		else
			pad = ' ';
		while (len < fmt->width && ++len)
			pf->len += put(&pad, 1);
	}
}

int
	convert(t_printf *pf, t_formatter *fmt)
{
	get_arg_at(fmt->pos, &pf->args);
	if (fmt->width < 0 && fmt->precision == -1)
		if ((fmt->width = ft_abs(fmt->width)))
			fmt->flags |= 1 << ft_indexof('-', FLAGS);
	return (convertion(pf, fmt));
}

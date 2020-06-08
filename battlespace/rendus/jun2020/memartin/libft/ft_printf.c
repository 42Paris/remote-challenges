/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 14:52:38 by memartin          #+#    #+#             */
/*   Updated: 2020/02/25 15:08:47 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_printf_init_flags(t_print *print)
{
	print->conv = '0';
	print->f_hash = 0;
	print->f_zero = 0;
	print->f_moins = 0;
	print->f_plus = 0;
	print->f_space = 0;
	print->m_h = 0;
	print->m_hh = 0;
	print->m_l = 0;
	print->m_ll = 0;
	print->m_j = 0;
	print->m_z = 0;
	print->precision = 0;
	print->width = 0;
	print->n_neg = 0;
	print->dot = 0;
	print->f_pre = 0;
	print->neg_pre = 0;
}

static void		ft_printf_init(t_print *print, const char *fmt)
{
	print->size = 0;
	print->buff_i = 0;
	print->fmt_i = 0;
	print->fmt = ft_strdup(fmt);
	ft_printf_init_flags(print);
}

int				ft_printf(const char *fmt, ...)
{
	t_print		p;

	va_start(p.arg, fmt);
	ft_printf_init(&p, fmt);
	while (fmt[p.fmt_i])
	{
		if (p.buff_i >= 3999)
			ft_printf_buffer(&p);
		if (fmt[p.fmt_i] != '%')
			ft_printf_add_char(&p, fmt);
		if (fmt[p.fmt_i] == '%' && fmt[p.fmt_i])
			ft_printf_parse(&p, fmt);
		ft_printf_init_flags(&p);
	}
	ft_printf_buffer(&p);
	ft_strdel(&p.fmt);
	va_end(p.arg);
	return (p.size);
}

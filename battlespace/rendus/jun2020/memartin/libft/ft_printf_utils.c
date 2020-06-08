/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 14:36:09 by memartin          #+#    #+#             */
/*   Updated: 2020/02/25 15:25:50 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_printf_precision_star(t_print *p, const char *fmt)
{
	while (fmt[p->fmt_i] == '*')
	{
		p->precision = va_arg(p->arg, int);
		p->fmt_i++;
	}
	if (p->precision == 0)
		p->precision = -1;
	else if (p->precision <= -1)
	{
		p->precision = 0;
		p->f_pre = 1;
	}
}

void		ft_printf_precision(t_print *p, const char *fmt)
{
	while (fmt[p->fmt_i] == '0' || fmt[p->fmt_i] == '.')
		p->fmt_i++;
	p->precision = ft_atoi(fmt + p->fmt_i);
	if (p->precision)
		p->fmt_i += ft_intmaxsize(p->precision);
	else if (p->precision <= 0)
		p->precision = -1;
}

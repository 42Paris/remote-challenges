/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_g.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 18:09:46 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/12 17:53:00 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_exponent(long double n)
{
	int e;

	if (!n)
		return (0);
	e = 0;
	n = (n < 0 ? -n : n);
	while (n >= 10)
	{
		e++;
		n /= 10;
	}
	while ((int64_t)n == 0)
	{
		e--;
		n *= 10;
	}
	return (e);
}

void			put_g(long double n, t_manager *p)
{
	int e;

	p->precision = (p->f.dot ? p->precision : 6);
	p->precision = (p->precision == 0 ? 1 : p->precision);
	e = get_exponent(n);
	if (p->precision > e && e >= -4)
	{
		p->precision = p->precision - (e + 1);
		put_f(n, p);
	}
	else
	{
		p->precision--;
		put_e(n, p);
	}
}

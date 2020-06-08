/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_e.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 15:30:53 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/12 17:50:44 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			get_exponent(long double *n, int e)
{
	if (!*n)
		return (0);
	while (*n >= 10)
	{
		e++;
		*n /= 10;
	}
	while ((int64_t)(*n) == 0)
	{
		e--;
		*n *= 10;
	}
	if ((int64_t)(*n) > 9)
	{
		e = (e < 0 ? e + 1 : e - 1);
		*n /= 10;
	}
	return (e);
}

static void			show_exp(int e, t_manager *p)
{
	char	s[2];

	write_buffer(p, "e", 1);
	write_buffer(p, (e < 0 ? "-" : "+"), 1);
	e = (e < 0 ? -e : e);
	s[0] = (e / 10) % 10 + '0';
	s[1] = e % 10 + '0';
	write_buffer(p, s, 2);
}

static long double	ft_round_e(long double n, size_t precision, int e)
{
	long double rnd;

	if (!n)
		return (0);
	rnd = 0.5;
	if (e >= 10)
		while (precision-- > 0)
			rnd *= 10;
	else
		while (precision-- > 0)
			rnd /= 10;
	return (n + rnd);
}

void				put_e(long double n, t_manager *p)
{
	char	is_neg;
	int		e;
	int		nb_char;

	p->precision = (p->f.dot ? p->precision : 6);
	is_neg = (n < 0 ? 1 : 0);
	n = (n < 0 ? -n : n);
	e = get_exponent(&n, 0);
	n = ft_round_e(n, p->precision, e);
	e = get_exponent(&n, e);
	if (p->specifier == 'g')
		p->precision = trailing_zero(n - (int)n, p->precision);
	nb_char = p->precision + 6 + (p->f.plus ? 1 : 0);
	if (p->f.space && !(is_neg || p->f.plus))
		if (p->width-- || 1)
			write_buffer(p, " ", 1);
	if (!p->f.dash)
		put_double_width(p, nb_char);
	if (is_neg || p->f.plus)
		write_buffer(p, (is_neg ? "-" : "+"), 1);
	put_double_zero(p, nb_char);
	put_double(n, p);
	show_exp(e, p);
	if (p->f.dash)
		put_double_width(p, nb_char);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_double.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:53:52 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/12 15:51:45 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t		get_nb_char(int64_t exp, char is_neg, t_manager *p)
{
	size_t nb_char;

	nb_char = (is_neg || p->f.plus);
	if (p->precision > 0 || p->f.hash)
		nb_char++;
	while ((exp /= 10))
		nb_char++;
	nb_char++;
	nb_char += p->precision;
	return (nb_char);
}

static long double	ft_round(long double n, size_t precision)
{
	long double rnd;

	rnd = 0.5;
	while (precision-- > 0)
		rnd /= 10;
	return (n + rnd);
}

void				put_f(long double n, t_manager *p)
{
	char	is_neg;
	int		nb_char;

	if (p->specifier != 'g')
		p->precision = (p->f.dot ? p->precision : 6);
	is_neg = (n < 0 ? 1 : 0);
	n = (n < 0 ? -n : n);
	n = ft_round(n, p->precision);
	if (p->specifier == 'g')
		p->precision = trailing_zero(n - (int)n, p->precision);
	nb_char = get_nb_char(n - (int64_t)n, is_neg, p);
	if (p->f.space && !(is_neg || p->f.plus))
	{
		write_buffer(p, " ", 1);
		p->width--;
	}
	if (!p->f.dash)
		put_double_width(p, nb_char);
	if (is_neg || p->f.plus)
		write_buffer(p, (is_neg ? "-" : "+"), 1);
	put_double_zero(p, nb_char);
	put_double(n, p);
	if (p->f.dash)
		put_double_width(p, nb_char);
}

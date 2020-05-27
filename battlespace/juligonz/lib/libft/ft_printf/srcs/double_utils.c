/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 17:36:20 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/12 16:42:08 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		put_exp(uint64_t exp, t_manager *p, size_t idx)
{
	char	c;

	c = exp % 10 + '0';
	if (exp >= 10)
	{
		put_exp(exp / 10, p, idx + 1);
		if (p->f.apostrophe && idx % 3 == 0)
			write_buffer(p, ",", 1);
	}
	write_buffer(p, &c, 1);
}

static void		put_mantis(long double mantis, int precision, t_manager *p)
{
	char c;

	mantis *= 10;
	c = (int)mantis + '0';
	write_buffer(p, &c, 1);
	if (precision > 1)
		put_mantis(mantis - (int)mantis, --precision, p);
}

void			put_double(long double n, t_manager *p)
{
	put_exp((int64_t)n, p, 1);
	if (p->precision > 0 || p->f.hash)
		write_buffer(p, ".", 1);
	if (p->precision > 0)
		put_mantis(n - (int64_t)n, p->precision, p);
}

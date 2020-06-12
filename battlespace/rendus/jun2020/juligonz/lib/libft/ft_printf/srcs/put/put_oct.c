/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_oct.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 14:26:02 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/12 17:39:55 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_width(t_manager *p, int nb_char)
{
	int	i;

	i = p->width;
	while (i > p->precision && i > nb_char)
	{
		write_buffer(p, " ", 1);
		i--;
	}
}

static void	put_precision(t_manager *p, int nb_char)
{
	int	i;

	if (p->f.zero && !p->f.dot)
		i = p->width;
	else
		i = p->precision;
	while (i > nb_char)
	{
		write_buffer(p, "0", 1);
		i--;
	}
}

static void	recursive(uint64_t n, t_manager *p, int *digits)
{
	char c;

	(*digits)++;
	c = n % 8 + '0';
	if (n >= 8)
		recursive(n / 8, p, digits);
	else
	{
		if (c == '0' && *digits == 1 && p->f.dot && p->precision == 0)
			(*digits) = 0;
		if (!p->f.dash && (!p->f.zero || p->f.dot))
			put_width(p, *digits);
		put_precision(p, *digits);
		if (*digits != 0 || !p->f.dot || p->precision != 0)
			write_buffer(p, &c, 1);
		return ;
	}
	write_buffer(p, &c, 1);
}

void		put_oct(int64_t n, t_manager *p)
{
	int nb_digit;

	nb_digit = 0;
	recursive(n, p, &nb_digit);
	if (p->f.dash)
		put_width(p, nb_digit);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:00:49 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/12 18:55:19 by juligonz         ###   ########.fr       */
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

static void	recursive(uint64_t n, t_manager *p, int *nb_digit)
{
	char c;

	(*nb_digit)++;
	c = n % 16 + '0';
	if (c > '9')
		c += (p->specifier == 'X' ? 7 : 39);
	if (n >= 16)
		recursive(n / 16, p, nb_digit);
	else
	{
		if (c == '0' && *nb_digit == 1 && p->f.dot && p->precision == 0)
			(*nb_digit) = 0;
		if (p->f.hash && *nb_digit > 0 && c != '0')
			p->width -= 2;
		if (!p->f.dash && (!p->f.zero || p->f.dot))
			put_width(p, *nb_digit);
		if ((p->f.hash && *nb_digit > 0 && c != '0'))
			write_buffer(p, (p->specifier == 'X' ? "0X" : "0x"), 2);
		put_precision(p, *nb_digit);
		if (*nb_digit != 0 || !p->f.dot || p->precision != 0)
			write_buffer(p, &c, 1);
		return ;
	}
	write_buffer(p, &c, 1);
}

void		put_hex(uint64_t n, t_manager *p)
{
	int nb_digit;

	nb_digit = 0;
	recursive(n, p, &nb_digit);
	if (p->f.dash)
		put_width(p, nb_digit);
}

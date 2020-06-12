/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 15:41:41 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/12 17:42:37 by juligonz         ###   ########.fr       */
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

static void	recursive(uint64_t n, t_manager *p, int *nb_digit)
{
	char c;

	(*nb_digit)++;
	c = n % 16 + '0';
	if (c > '9')
		c += 39;
	if (n >= 16)
		recursive(n / 16, p, nb_digit);
	else
	{
		if (c == '0' && *nb_digit == 1 && p->f.dot && p->precision == 0)
			*nb_digit = 0;
		p->width -= 2;
		if (!p->f.dash)
			put_width(p, *nb_digit);
		write_buffer(p, "0x", 2);
		if (*nb_digit)
			write_buffer(p, &c, 1);
		return ;
	}
	write_buffer(p, &c, 1);
}

void		put_ptr(uint64_t n, t_manager *p)
{
	int nb_digit;

	nb_digit = 0;
	recursive(n, p, &nb_digit);
	if (p->f.dash)
		put_width(p, nb_digit);
}

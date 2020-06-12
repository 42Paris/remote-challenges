/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:41:07 by hbaudet           #+#    #+#             */
/*   Updated: 2020/01/03 11:10:59 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_char(unsigned char c, t_uint *f)
{
	t_uint	co;

	co = 0;
	while (!f[3] && f[2] > co + 1)
		co += write(1, " ", 1);
	while (!f[3] && f[6] && co + 1 < f[0])
		co += write(1, "0", 1);
	co += write(1, &c, 1);
	while (f[3] && f[2] > co)
		co += write(1, " ", 1);
	ft_bzero(f, 7 * sizeof(int));
	return (co);
}

int	int_neg(int nb, t_uint *f)
{
	int		tmp;
	t_uint	i;
	t_uint	c;
	t_uint	j;

	i = 1;
	tmp = nb;
	c = 0;
	while (tmp /= 10)
		i++;
	while (!f[3] && ((f[1] >= i && c + f[1] + 1 < f[2])
		|| (f[1] < i && c + i + 1 < f[2])))
		c += write(1, " ", 1);
	c += write(1, "-", 1);
	j = i;
	while ((f[5] && f[1] > j++) || (f[6] && f[0] > ++i))
		c += write(1, "0", 1);
	c += ft_putnbr_printf(nb, 1, f);
	while (f[3] && c < f[2])
		c += write(1, " ", 1);
	ft_bzero(f, 7 * sizeof(int));
	return (c);
}

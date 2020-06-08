/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:20:59 by hbaudet           #+#    #+#             */
/*   Updated: 2019/12/11 16:18:50 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print(unsigned long long toprint, int fd, int *count)
{
	if (toprint >= 10)
		ft_print(toprint / 10, fd, count);
	ft_putchar_fd(toprint % 10 + 48, fd);
	(*count)++;
}

int			ft_putnbr_printf(long long n, int fd, t_uint *f)
{
	unsigned long long	nb_posi;
	int					c;

	c = 0;
	if (f[5] && !f[1] && !n)
	{
		if (f[6] || f[4])
			c += write(1, " ", 1);
		return (c);
	}
	if (n < 0)
		nb_posi = (t_uint)(n * -1);
	else
		nb_posi = (t_uint)n;
	ft_print(nb_posi, fd, &c);
	return (c);
}

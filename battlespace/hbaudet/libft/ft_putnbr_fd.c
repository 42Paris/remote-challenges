/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 16:20:59 by hbaudet           #+#    #+#             */
/*   Updated: 2019/12/11 16:18:49 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print(t_uint toprint, int fd)
{
	if (toprint >= 10)
		ft_print(toprint / 10, fd);
	ft_putchar_fd(toprint % 10 + 48, fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	t_uint	nb_posi;

	if (n < 0)
	{
		write(fd, "-", 1);
		nb_posi = (t_uint)(n * -1);
	}
	else
		nb_posi = (t_uint)n;
	ft_print(nb_posi, fd);
}

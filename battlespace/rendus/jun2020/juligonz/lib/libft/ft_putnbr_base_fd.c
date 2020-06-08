/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 16:06:55 by juligonz          #+#    #+#             */
/*   Updated: 2019/10/08 09:06:57 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbru_base_fd(unsigned int n, unsigned int *base, int *fd)
{
	char c;

	if (n >= *base)
		ft_putnbru_base_fd(n / *base, base, fd);
	c = n % *base + '0';
	if (c > '9')
		c += 39;
	ft_putchar_fd(c, *fd);
}

void		ft_putnbr_base_fd(int n, unsigned int base, int fd)
{
	if (base > 16 || base < 2)
		return ;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbru_base_fd(-n, &base, &fd);
	}
	else
		ft_putnbru_base_fd(n, &base, &fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:22:23 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/18 16:48:38 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** RECURSIF
** void	ft_putnbr(int nb)
** {
** 	unsigned int n;
** 	n = nb;
**	if (nb < 0)
**	{
**		n *= -1;
**		ft_putchar('-');
**	}
**	if (n / 10)
**		ft_putnbr(n / 10);
**	ft_putchar('0' + (n % 10));
** }
*/

void	ft_putnbr(long nb)
{
	unsigned long	len;
	unsigned long	n;
	unsigned long	m;

	len = 1;
	n = (unsigned long)nb;
	if (nb < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	m = n;
	while (m /= 10)
		len *= 10;
	ft_putchar('0' + ((n / len) % 10));
	while (len /= 10)
		ft_putchar('0' + ((n / len) % 10));
}

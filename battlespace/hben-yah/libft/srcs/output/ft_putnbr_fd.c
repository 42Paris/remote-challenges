/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:23:36 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/18 16:48:12 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** void	ft_putnbr_fd(int nb, int fd)
** {
**	unsigned int n;
**
**	n = nb;
**	if (nb < 0)
**	{
**		n *= -1;
**		ft_putchar_fd('-', fd);
**	}
**	if (n > 9)
**		ft_putnbr_fd(n / 10, fd);
**	ft_putchar_fd('0' + (n % 10), fd);
** }
*/

void	ft_putnbr_fd(long nb, int fd)
{
	unsigned long	len;
	unsigned long	n;
	unsigned long	m;

	len = 1;
	n = (unsigned long)nb;
	if (nb < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	m = n;
	while (m /= 10)
		len *= 10;
	ft_putchar_fd('0' + ((n / len) % 10), fd);
	while (len /= 10)
		ft_putchar_fd('0' + ((n / len) % 10), fd);
}

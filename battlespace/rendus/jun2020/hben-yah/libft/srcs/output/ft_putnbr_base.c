/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:14:54 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/18 16:47:33 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_error(char *base, size_t len)
{
	if (len < 2 || !ft_hasnodupl(base))
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-' || *base < ' ' || *base > '~')
			return (0);
		++base;
	}
	return (1);
}

void		ft_putnbr_base(long nb, char *base)
{
	unsigned long	n;
	unsigned long	m;
	unsigned long	base_len;

	base_len = ft_strlen(base);
	if (ft_check_error(base, base_len))
		return ;
	n = nb;
	if (nb < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	m = 0;
	while (n)
	{
		m *= base_len;
		m += n % base_len;
		n /= base_len;
	}
	ft_putchar(base[m % base_len]);
	while (m /= base_len)
		ft_putchar(base[m % base_len]);
}

void		ft_putnbr_base_fd(long nb, char *base, int fd)
{
	unsigned long	n;
	unsigned long	m;
	unsigned long	base_len;

	base_len = ft_strlen(base);
	if (ft_check_error(base, base_len))
		return ;
	n = nb;
	if (nb < 0)
	{
		n *= -1;
		ft_putchar_fd('-', fd);
	}
	m = 0;
	while (n)
	{
		m *= base_len;
		m += n % base_len;
		n /= base_len;
	}
	ft_putchar_fd(base[m % base_len], fd);
	while (m /= base_len)
		ft_putchar_fd(base[m % base_len], fd);
}

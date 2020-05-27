/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 19:46:41 by juligonz          #+#    #+#             */
/*   Updated: 2019/10/08 09:09:51 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbru_fd(unsigned int n, int *fd)
{
	if (n >= 10)
		ft_putnbru_fd(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', *fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbru_fd(-n, &fd);
	}
	else
		ft_putnbru_fd(n, &fd);
}

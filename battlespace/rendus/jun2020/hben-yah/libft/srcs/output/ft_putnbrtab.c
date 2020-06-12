/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrtab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 19:03:51 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/10 15:01:59 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbrtab(int *tab, size_t size)
{
	while (tab && size--)
	{
		ft_putnbr(*(tab++));
		ft_putchar('\n');
	}
}

void	ft_putnbrtab_fd(int *tab, size_t size, int fd)
{
	while (tab && size--)
	{
		ft_putnbr_fd(*(tab++), fd);
		ft_putchar_fd('\n', fd);
	}
}

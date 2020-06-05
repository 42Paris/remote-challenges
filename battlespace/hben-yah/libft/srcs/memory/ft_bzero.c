/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:55:06 by hben-yah          #+#    #+#             */
/*   Updated: 2019/06/18 11:22:24 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*c;
	unsigned long	*l;
	size_t			ls;
	short			left;

	if (n < 1)
		return ;
	c = (unsigned char *)s;
	ls = sizeof(long);
	left = (long)c % ls;
	left = (left != 0 ? ls - left : 0);
	while (left && n--)
	{
		*(c++) = 0;
		--left;
	}
	l = (unsigned long *)c;
	while (n >= ls)
	{
		*(l++) = 0;
		n -= ls;
	}
	c = (unsigned char *)l;
	while (n--)
		*(c++) = 0;
}

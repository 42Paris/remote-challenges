/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmath.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 10:31:19 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:19:22 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	str_power(unsigned char *p, long a, int b, int len)
{
	int i;

	i = 0;
	if (b == 0)
		return ;
	if (b > 0)
	{
		while (i++ < b)
			str_multi(p, a, len);
	}
	else
	{
		while (i-- > b)
		{
			if (a == 2)
				str_divi_2(p, len);
			else
				str_divi(p, a, len);
		}
	}
}

void	str_add(unsigned char *a, unsigned char *b, int len)
{
	unsigned long	c;
	unsigned long	left;
	int				i;

	i = 0;
	left = 0;
	while (i < len)
	{
		c = *(a + len - i) + *(b + len - i) + left;
		*(a + len - i) = c % 10;
		left = c / 10;
		++i;
	}
}

void	str_multi(unsigned char *a, int b, int len)
{
	unsigned long	c;
	unsigned long	left;
	int				i;

	i = 0;
	left = 0;
	while (i < len)
	{
		c = *(a + len - i) * b + left;
		*(a + len - i) = c % 10;
		left = c / 10;
		++i;
	}
}

void	str_divi(unsigned char *a, int b, int len)
{
	unsigned long	c;
	unsigned long	left;
	int				i;
	int				j;
	int				k;

	i = 0;
	left = 0;
	while (i < len)
	{
		c = *(a + i);
		j = 0;
		while (c % b)
		{
			c *= 10;
			++j;
		}
		c /= b;
		k = ft_pow(10, j);
		*(a + i) = c / k + left;
		left = c % k;
		++i;
	}
}

void	str_divi_2(unsigned char *a, int len)
{
	unsigned int	c;
	unsigned int	left;
	int				i;

	i = 0;
	left = 0;
	while (i < len)
	{
		c = *(a + i);
		*(a + i) = c / 2 + left;
		left = c % 2 ? 5 : 0;
		++i;
	}
}

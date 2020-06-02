/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:54:00 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/03 17:54:01 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*d1;
	unsigned char	*d2;

	if (n == 0)
		return (0);
	d1 = (unsigned char *)s1;
	d2 = (unsigned char *)s2;
	while (*d1 == *d2 && --n)
	{
		d1++;
		d2++;
	}
	return (int)(*d1 - *d2);
}

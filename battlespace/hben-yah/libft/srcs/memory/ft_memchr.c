/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:54:07 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/03 17:54:09 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *d;
	unsigned char chara;

	d = (unsigned char *)s;
	chara = (unsigned char)c;
	while (n--)
	{
		if (*d == chara)
			return ((void *)d);
		d++;
	}
	return (NULL);
}

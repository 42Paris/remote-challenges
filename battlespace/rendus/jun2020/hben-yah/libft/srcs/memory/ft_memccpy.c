/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:54:35 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/03 17:54:36 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	chara;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	chara = (unsigned char)c;
	while (n-- > 0)
	{
		*d = *s;
		if (*(d++) == chara)
			return ((void *)d);
		s++;
	}
	return (NULL);
}

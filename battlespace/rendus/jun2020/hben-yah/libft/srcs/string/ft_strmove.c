/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:16:55 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/27 14:21:53 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmove(char *dst, const char *src)
{
	char *d;

	d = dst;
	if (src < dst)
	{
		while (*src)
			*(d++) = *(src++);
		*d = *src;
	}
	else
		ft_strcpy(d, src);
	return (dst);
}

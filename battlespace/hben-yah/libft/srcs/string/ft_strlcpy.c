/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 15:06:21 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/08 15:41:38 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char *d;

	d = (char *)src;
	if (size > 0)
	{
		while (*src && (size_t)(src - d) < size - 1)
			*(dst++) = *(src++);
		*dst = 0;
	}
	while (*src)
		++src;
	return (size_t)(src - d);
}

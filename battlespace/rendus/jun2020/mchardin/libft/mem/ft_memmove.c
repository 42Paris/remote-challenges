/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:58:15 by mchardin          #+#    #+#             */
/*   Updated: 2019/11/13 10:20:37 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*temp_src;
	unsigned char		*temp_dst;

	if (dst == src)
		return (dst);
	temp_src = src;
	temp_dst = dst;
	if (src < dst && dst < src + len)
	{
		temp_src += len;
		temp_dst += len;
		while (len--)
			*--temp_dst = *--temp_src;
	}
	else
		while (len--)
			*temp_dst++ = *temp_src++;
	return (dst);
}

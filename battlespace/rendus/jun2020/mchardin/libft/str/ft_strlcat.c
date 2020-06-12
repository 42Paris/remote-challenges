/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 12:20:25 by mchardin          #+#    #+#             */
/*   Updated: 2020/04/22 22:43:25 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	lg_src;
	size_t	lg_dst;

	i = 0;
	lg_src = 0;
	lg_dst = 0;
	while (src[lg_src])
		lg_src++;
	while (dst[lg_dst] && lg_dst < dstsize)
		lg_dst++;
	j = lg_src;
	if (dstsize <= lg_dst)
		return (dstsize + lg_src);
	while (dstsize - 1 > i + lg_dst && j > 0)
	{
		dst[lg_dst + i] = src[i];
		i++;
		j--;
	}
	dst[lg_dst + i] = '\0';
	return (lg_dst + lg_src);
}

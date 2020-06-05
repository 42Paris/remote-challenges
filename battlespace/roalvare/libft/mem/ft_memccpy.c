/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 14:56:18 by roalvare          #+#    #+#             */
/*   Updated: 2019/10/14 15:44:05 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*crs_dst;
	const unsigned char	*crs_src;
	unsigned char		stop_c;

	crs_src = src;
	crs_dst = dst;
	stop_c = (unsigned char)c;
	while (n-- > 0)
	{
		*crs_dst++ = *crs_src++;
		if (*(crs_src - 1) == stop_c)
			return (crs_dst);
	}
	return (NULL);
}

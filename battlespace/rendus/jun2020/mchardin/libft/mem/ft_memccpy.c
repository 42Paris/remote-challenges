/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:59:06 by mchardin          #+#    #+#             */
/*   Updated: 2019/11/13 10:10:36 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*temp_src;
	unsigned char		*temp_dst;
	size_t				i;

	i = 0;
	temp_src = src;
	temp_dst = dst;
	while (i < n)
	{
		temp_dst[i] = temp_src[i];
		if ((unsigned char)c == temp_src[i])
			return (&temp_dst[i + 1]);
		i++;
	}
	return (0);
}

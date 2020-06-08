/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:25:39 by juligonz          #+#    #+#             */
/*   Updated: 2019/10/08 15:05:46 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char *d;
	char *s;

	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (char *)src;
	while (n-- > 0)
		*d++ = *s++;
	return (dest);
}

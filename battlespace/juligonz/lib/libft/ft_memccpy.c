/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 20:26:43 by juligonz          #+#    #+#             */
/*   Updated: 2019/10/07 20:27:48 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = dest;
	s = (char *)src;
	while (n-- > 0)
	{
		d[i] = s[i];
		if ((unsigned char)s[i] == (unsigned char)c)
			return (d + i + 1);
		i++;
	}
	return (NULL);
}

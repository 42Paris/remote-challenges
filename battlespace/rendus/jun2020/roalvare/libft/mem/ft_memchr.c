/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:34:02 by roalvare          #+#    #+#             */
/*   Updated: 2019/10/09 10:41:26 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	byte;
	unsigned char	*cursor;

	byte = c;
	cursor = (unsigned char*)s;
	while (n-- > 0)
	{
		if (*cursor == byte)
			return (cursor);
		cursor++;
	}
	return (NULL);
}

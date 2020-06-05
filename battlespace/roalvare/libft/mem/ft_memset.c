/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:27:09 by roalvare          #+#    #+#             */
/*   Updated: 2019/10/14 17:06:41 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	byte;
	unsigned char	*cursor;
	size_t			i;

	byte = (unsigned char)c;
	cursor = b;
	i = 0;
	while (i < len)
	{
		*cursor = byte;
		cursor++;
		i++;
	}
	return (b);
}

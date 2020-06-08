/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unicode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:18:48 by memartin          #+#    #+#             */
/*   Updated: 2020/02/24 15:28:03 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ascii(unsigned char *buff, int c)
{
	buff[0] = c;
	return (1);
}

int				ft_printf_unicode(unsigned char *buff, int c)
{
	if (c <= 0x7F)
		return (ft_ascii(buff, c));
	else if (c <= 0x7FF)
	{
		buff[0] = 0xC0 | (c >> 6);
		buff[1] = 0x80 | (c & 0x3F);
		return (2);
	}
	else if (c <= 0xFFFF)
	{
		buff[0] = 0xE0 | (c >> 12);
		buff[1] = 0x80 | ((c >> 6) & 0x3F);
		buff[2] = 0x80 | (c & 0x3F);
		return (3);
	}
	else if (c <= 0xFFFFF)
	{
		buff[0] = 0xF0 | (c >> 18);
		buff[1] = 0x80 | ((c >> 12) & 0x3F);
		buff[2] = 0x80 | ((c >> 6) & 0x3F);
		buff[3] = 0x80 | (c & 0x3F);
		return (4);
	}
	return (0);
}

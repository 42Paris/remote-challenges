/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wchar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 00:40:59 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:19:27 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	wchartoa(char *s, wint_t w)
{
	size_t	ret;

	ret = 0;
	if (w >= 0x110000)
		return (0);
	if (MB_CUR_MAX == 1 && w >= 0x80 && w < 0x100)
		w -= 256;
	if (w >= 0)
	{
		if (w >= 0x10000 && ++ret)
			*(s++) = ((w >> 18) & 0x7) | 0xF0;
		if (w >= 0x800)
			*(s++) = !ret++ ? ((w >> 12) & 0xF) | 0xE0
							: ((w >> 12) & 0x3F) | 0x80;
		if (w >= 0x80)
			*(s++) = !ret++ ? ((w >> 6) & 0x1F) | 0xC0
							: ((w >> 6) & 0x3F) | 0x80;
		*s = !ret ? w & 0x7F : (w & 0x3F) | 0x80;
	}
	else
		*s = w;
	return (++ret);
}

size_t	wstrtoa(char *s, const wchar_t *wstr)
{
	size_t	ret;

	ret = 0;
	while (*wstr)
		ret += wchartoa(s + ret, (wint_t)*(wstr++));
	return (ret);
}

size_t	wstrntoa(char *s, const wchar_t *wstr, size_t n)
{
	size_t	ret;
	size_t	len;

	ret = 0;
	while (*wstr)
	{
		len = wchartoa(s + ret, (wint_t)*(wstr++));
		if (ret + len > n)
			break ;
		ret += len;
	}
	return (ret);
}

int		check_unicode(wint_t *c)
{
	return (!((*c < 0) || (MB_CUR_MAX == 1 && *c >= 0x100)
		|| (*c >= 0xD800 && *c <= 0xDBFF) || (*c >= 0xDC00 && *c <= 0xDFFF)));
}

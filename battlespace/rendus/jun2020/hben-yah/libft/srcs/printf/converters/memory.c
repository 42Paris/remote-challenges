/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:52:34 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:19:05 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void
	print_hexadecimal(const unsigned char *s, size_t size, size_t i,
																t_printf *pf)
{
	const char	*base = "0123456789ABCDEF";
	size_t		j;

	j = 0;
	while (j < 16 && j + i < size)
	{
		pf->len += put((char *)&base[*(s + i + j) / 16], 1);
		pf->len += put((char *)&base[*(s + i + j) % 16], 1);
		if (j % 2 == 1)
			pf->len += put(" ", 1);
		++j;
	}
	while (j < 16)
	{
		pf->len += put("  ", 2);
		if (j % 2 == 1)
			pf->len += put(" ", 1);
		++j;
	}
}

static void
	print_memory(const void *addr, size_t size, t_printf *pf)
{
	const unsigned char	*s = (unsigned char *)addr;
	size_t				i;
	size_t				j;

	i = 0;
	if (pf->len > 0)
		pf->len += put("\n", 1);
	while (i < size)
	{
		print_hexadecimal(s, size, i, pf);
		j = -1;
		while (++j < 16 && j + i < size)
			if (ft_isprint(*(s + i + j)))
				pf->len += put((char *)(s + i + j), 1);
			else
				pf->len += put(".", 1);
		pf->len += put("\n", 1);
		i += 16;
	}
}

int	convert_m(t_printf *pf, t_formatter *fmt, va_list ap)
{
	int		*arg;
	size_t	beg;
	size_t	end;

	arg = va_arg(ap, int *);
	beg = pf->len;
	print_memory(arg, fmt->width, pf);
	end = pf->len;
	return (end - beg);
}

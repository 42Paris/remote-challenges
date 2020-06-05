/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:34:31 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:18:30 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		convert_char(t_printf *pf, t_formatter *fmt, va_list ap)
{
	unsigned char	chara;
	int				before;

	if (fmt->length & (1 << ft_indexof('l', LENGTHS)))
		return (convert_wchar(pf, fmt, ap));
	chara = (unsigned char)va_arg(ap, unsigned);
	fmt->precision = -1;
	if ((before = !is_flag('-', *fmt)))
		fill_width_chr(pf, fmt, 1);
	pf->len += put((void *)&chara, 1);
	if (!before)
		fill_width_chr(pf, fmt, 1);
	return (1);
}

int		convert_wchar(t_printf *pf, t_formatter *fmt, va_list ap)
{
	wint_t	chara;
	size_t	ret;
	int		before;
	char	buff[256];

	chara = va_arg(ap, wint_t);
	fmt->precision = -1;
	if ((before = !is_flag('-', *fmt)))
		fill_width_chr(pf, fmt, 4);
	if (!check_unicode(&chara)
		|| !(ret = wchartoa(buff, chara)))
		return (-1);
	pf->len += put(buff, ret);
	if (!before)
		fill_width_chr(pf, fmt, 4);
	pf->len += ret;
	return ((int)ret);
}

int		convert_const(t_printf *pf, t_formatter *fmt)
{
	unsigned char	chara;
	int				before;

	chara = (unsigned char)fmt->converter;
	fmt->precision = -1;
	if ((before = !is_flag('-', *fmt)))
		fill_width_chr(pf, fmt, 1);
	pf->len += put((void *)&chara, 1);
	if (!before)
		fill_width_chr(pf, fmt, 1);
	return (1);
}

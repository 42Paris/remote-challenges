/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   non_printable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 14:50:50 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:19:07 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void
	print_non_printable(char *str, size_t n, t_printf *pf)
{
	const char *base = "0123456789abcdef";

	while (*str && n--)
	{
		if (*str < ' ' || *str == 127)
		{
			pf->len += put("\\", 1);
			pf->len += put((char *)&base[*str / 16], 1);
			pf->len += put((char *)&base[*str % 16], 1);
		}
		else
			pf->len += put(str, 1);
		++str;
	}
}

int	convert_r(t_printf *pf, t_formatter *fmt, va_list ap)
{
	char	*str;
	int		ret;
	int		before;

	if (!(str = va_arg(ap, char *)))
		str = "(null)";
	if (fmt->precision <= -1)
		ret = ft_strlen(str);
	else
		ret = ft_min(ft_strlen(str), fmt->precision);
	fmt->precision = -1;
	if ((before = !is_flag('-', *fmt)))
		fill_width_chr(pf, fmt, ret);
	print_non_printable(str, ret, pf);
	if (!before)
		fill_width_chr(pf, fmt, ret);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:12:42 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:19:11 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		convert_str(t_printf *pf, t_formatter *fmt, va_list ap)
{
	char	*str;
	int		ret;
	int		before;

	if (is_length('l', *fmt, 1))
		return (convert_wstr(pf, fmt, ap));
	else if (!(str = va_arg(ap, char *)))
		str = "(null)";
	if (fmt->precision <= -1)
		ret = ft_strlen(str);
	else
		ret = ft_min(ft_strlen(str), fmt->precision);
	fmt->precision = -1;
	if ((before = !is_flag('-', *fmt)))
		fill_width_chr(pf, fmt, ret);
	pf->len += put(str, ret);
	if (!before)
		fill_width_chr(pf, fmt, ret);
	return (ret);
}

int		convert_wstr(t_printf *pf, t_formatter *fmt, va_list ap)
{
	wchar_t	*wstr;
	wchar_t	*a;
	int		ret;
	int		before;
	char	buff[256];

	ret = 0;
	if (!(wstr = va_arg(ap, wchar_t *)))
		wstr = L"(null)";
	a = wstr;
	while (*a && (fmt->precision == -1 || ret < fmt->precision))
		if (ret++ && !check_unicode((wint_t *)a++))
			return (-1);
	ret = 4 * (a - wstr);
	if ((before = !is_flag('-', *fmt)))
		fill_width_chr(pf, fmt, ret);
	if (fmt->precision > -1)
		ret = wstrntoa(buff, wstr, fmt->precision);
	else
		ret = wstrtoa(buff, wstr);
	pf->len += put(buff, ret);
	if (!before)
		fill_width_chr(pf, fmt, ret);
	fmt->precision = -1;
	return (pf->len);
}

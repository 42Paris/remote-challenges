/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 19:15:12 by juligonz          #+#    #+#             */
/*   Updated: 2020/03/25 10:41:34 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_wcslen_no_locale(const wchar_t *ws)
{
	int i;

	i = 0;
	while (ws[i])
	{
		if (ws[i] > 255)
			return (-1);
		i++;
	}
	return (i);
}

void		conv_s(va_list args, t_manager *p)
{
	char	*s;
	int		len;

	s = (char *)cast_s(p, args);
	if (!s)
		s = "(null)";
	len = (p->f.l ? ft_wcslen_no_locale((wchar_t *)s) : (int)ft_strlen(s));
	if (len == -1)
	{
		p->is_error = 1;
		return ;
	}
	if (p->f.dot && p->precision < len && p->precision >= 0)
		len = p->precision;
	p->width -= len;
	if (!p->f.dash)
		while (p->width-- > 0)
			write_buffer(p, " ", 1);
	if (!p->f.l)
		write_buffer(p, s, len);
	else
		write_buffer_wcs(p, (wchar_t *)s, len);
	if (p->f.dash)
		while (p->width-- > 0)
			write_buffer(p, " ", 1);
}

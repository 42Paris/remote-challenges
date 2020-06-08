/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 12:29:54 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/03 15:35:28 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_vsprintf(char *dst, const char *format, va_list ap)
{
	size_t		i;
	char		*str;
	t_manager	p;

	str = (char *)format;
	ft_memset(&p, 0, sizeof(t_manager));
	p.caller = SPRINTF;
	p.dst = dst;
	i = -1;
	while (format[++i])
		if (format[i] == '%')
		{
			write_buffer(&p, str, format + i++ - str);
			i += read_flags(&p, ap, format + i);
			if (!p.specifier)
				break ;
			parse(ap, &p);
			str = (char *)format + i + 1;
		}
	write_buffer(&p, str, format + i - str);
	flush_buffer(&p);
	return (p.len);
}

int		ft_sprintf(char *str, const char *format, ...)
{
	int		len;
	va_list	ap;

	va_start(ap, format);
	len = ft_vsprintf(str, format, ap);
	va_end(ap);
	return (len);
}

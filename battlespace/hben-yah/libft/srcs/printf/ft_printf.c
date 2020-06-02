/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 01:01:05 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:57:51 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = ft_vprintf(format, ap);
	va_end(ap);
	return (ret);
}

void	get_arg_at(int pos, t_arglist *args)
{
	if (pos)
	{
		va_copy(args->selected, args->begin);
		while (--pos >= 1)
			va_arg(args->selected, void *);
	}
}

int		handle_formatter(t_printf *pf)
{
	t_formatter	fmt;

	parse_formatter(&fmt, pf);
	fmt.prev_len = pf->len;
	if (fmt.converter)
		return (convert(pf, &fmt));
	return (0);
}

int		ft_vprintf(const char *format, va_list ap)
{
	t_printf	pf;

	ft_bzero(&pf, sizeof(t_printf));
	va_copy(pf.args.begin, ap);
	va_copy(pf.args.natural, ap);
	va_copy(pf.args.selected, ap);
	pf.format = (char *)format;
	while (*(pf.next = walk_format(pf.format, '%')))
	{
		pf.len += put(pf.format, pf.next - pf.format);
		if (handle_formatter(&pf) == -1)
		{
			put(0, -1);
			return (-1);
		}
		pf.format = pf.next;
	}
	pf.len += put(pf.format, pf.next - pf.format);
	put(0, -1);
	return (pf.len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatter_parser.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 19:31:09 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:19:18 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void
	set_width(t_formatter *fmt, t_printf *pf)
{
	fmt->width = 0;
	while ('0' <= *pf->next && *pf->next <= '9')
		fmt->width = (10 * fmt->width) + *(pf->next++) - '0';
	--pf->next;
}

static void
	set_width_from_arg(t_formatter *fmt, t_printf *pf)
{
	int		nwidth;
	int		i;
	va_list tmp;

	va_copy(tmp, pf->args.begin);
	++pf->next;
	nwidth = 0;
	while ('0' <= *pf->next && *pf->next <= '9')
		nwidth = (10 * nwidth) + *(pf->next++) - '0';
	if (*pf->next == '$')
	{
		i = nwidth;
		while (i--)
			fmt->width = va_arg(tmp, unsigned);
	}
	else
	{
		fmt->width = va_arg(pf->args.natural, unsigned);
		if (nwidth > 0)
			fmt->width = nwidth;
		--pf->next;
	}
}

static void
	set_length_modifier(t_formatter *fmt, char c, int index)
{
	int i;

	i = 1 << index;
	if ((c == 'h' || c == 'l') && (fmt->length & i))
		fmt->length |= i << 1;
	else if (fmt->length == 0
		|| !(c == 'h' && (fmt->length & (3 << index)) != 3))
		fmt->length = i;
}

static void
	set_precision(t_formatter *fmt, t_printf *pf)
{
	if (*(++pf->next) == '*')
		fmt->precision = va_arg(pf->args.natural, unsigned);
	else
	{
		fmt->precision = 0;
		while ('0' <= *pf->next && *pf->next <= '9')
			fmt->precision = (10 * fmt->precision) + *(pf->next++) - '0';
		--pf->next;
	}
}

void
	parse_formatter(t_formatter *fmt, t_printf *pf)
{
	int	index;

	ft_bzero(fmt, sizeof(t_formatter));
	fmt->precision = -1;
	while (*(++pf->next))
		if ('1' <= *pf->next && *pf->next <= '9')
			set_width(fmt, pf);
		else if (*pf->next == '*')
			set_width_from_arg(fmt, pf);
		else if ((index = ft_indexof(*pf->next, FLAGS)) >= 0)
			fmt->flags |= (1 << index);
		else if ((index = ft_indexof(*pf->next, LENGTHS)) >= 0)
			set_length_modifier(fmt, *pf->next, index);
		else if (*pf->next == '.')
			set_precision(fmt, pf);
		else if (*pf->next == '$')
		{
			if (fmt->pos == 0 && (fmt->pos = fmt->width))
				fmt->width = 0;
		}
		else if ((fmt->converter = *pf->next) && ++pf->next)
			break ;
}

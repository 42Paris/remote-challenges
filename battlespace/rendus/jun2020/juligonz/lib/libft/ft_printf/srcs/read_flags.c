/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 15:59:07 by juligonz          #+#    #+#             */
/*   Updated: 2020/01/31 15:48:57 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_modifier(t_manager *p, const char *format, size_t *i)
{
	if (format[*i] == 'l' && ++(*i))
	{
		if (format[*i] == 'l' && ++(*i))
			p->f.ll = 1;
		else
			p->f.l = 1;
	}
	else if (format[*i] == 'h' && ++(*i))
	{
		if (format[*i] == 'h' && ++(*i))
			p->f.hh = 1;
		else
			p->f.h = 1;
	}
	else if (format[*i] == 'j' && ++(*i))
		p->f.j = 1;
	else if (format[*i] == 'L' && ++(*i))
		p->f.l_uppercase = 1;
	else
		return (0);
	return (1);
}

static int	primary_flags(t_manager *p, const char *format, size_t *i)
{
	if (format[*i] == '-' && ++(*i))
	{
		p->f.dash = 1;
		p->f.zero = 0;
	}
	else if (format[*i] == '0' && !(p->f.dash) && ++(*i))
		p->f.zero = 1;
	else if (format[*i] == '+' && ++(*i))
		p->f.plus = 1;
	else if (format[*i] == '#' && ++(*i))
		p->f.hash = 1;
	else if (format[*i] == ' ' && ++(*i))
		p->f.space = 1;
	else if (format[*i] == '\'' && ++(*i))
		p->f.apostrophe = 1;
	else
		return (0);
	return (1);
}

static int	width(t_manager *p, const char *format, size_t *i, va_list args)
{
	if (ft_isdigit(format[*i]))
		while (ft_isdigit(format[*i]))
			p->width = (p->width * 10) + format[(*i)++] - '0';
	else if (format[*i] == '*' && ++(*i))
	{
		if ((p->width = va_arg(args, size_t)) < 0)
		{
			p->f.dash = 1;
			p->width = -(p->width);
			p->f.zero = 0;
		}
		p->f.star = 1;
	}
	else
		return (0);
	return (1);
}

static int	preci(t_manager *p, const char *format, size_t *i, va_list args)
{
	if (format[*i] == '.' && ++(*i))
	{
		p->f.dot = 1;
		if (format[*i] == '*' && ++(*i))
			p->precision = va_arg(args, int);
		else
			while (ft_isdigit(format[*i]))
				p->precision = (p->precision * 10) + format[(*i)++] - '0';
		if (p->precision < 0)
			p->f.dot = 0;
	}
	else
		return (0);
	return (1);
}

int			read_flags(t_manager *p, va_list args, const char *format)
{
	size_t i;

	p->width = 0;
	p->precision = 0;
	ft_memset(&(p->f), 0, sizeof(t_flags));
	i = 0;
	while (1)
	{
		if (!primary_flags(p, format, &i)
			&& !len_modifier(p, format, &i)
			&& !width(p, format, &i, args)
			&& !preci(p, format, &i, args))
		{
			p->specifier = format[i];
			return (i);
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:26:57 by memartin          #+#    #+#             */
/*   Updated: 2020/02/25 15:27:32 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printf_check_flags(t_print *p, char c)
{
	if (c == '#')
		p->f_hash = 1;
	else if (c == '0' && p->fmt[p->fmt_i] != '.')
		p->f_zero = 1;
	else if (c == '-')
		p->f_moins = 1;
	else if (c == '+')
		p->f_plus = 1;
	else if (c == ' ')
		p->f_space = 1;
	else
		return (0);
	p->fmt_i++;
	return (1);
}

static int	ft_printf_check_modifier(t_print *p, const char *fmt)
{
	if (fmt[p->fmt_i] == 'l')
	{
		if (fmt[p->fmt_i + 1] && fmt[p->fmt_i + 1] == 'l' && p->fmt_i++)
			p->m_ll = 1;
		else
			p->m_l = 1;
	}
	else if (fmt[p->fmt_i] == 'h')
	{
		if (fmt[p->fmt_i + 1] && fmt[p->fmt_i + 1] == 'h' && p->fmt_i++)
			p->m_hh = 1;
		else
			p->m_h = 1;
	}
	else if (fmt[p->fmt_i] == 'j')
		p->m_j = 1;
	else if (fmt[p->fmt_i] == 'z')
		p->m_z = 1;
	else
		return (0);
	p->fmt_i++;
	return (1);
}

static int	ft_printf_check_width(t_print *p, const char *fmt)
{
	if ((fmt[p->fmt_i] == '*' || ft_isdigit(fmt[p->fmt_i])) &&
		fmt[p->fmt_i - 1] != '.')
	{
		if (fmt[p->fmt_i] == '*')
		{
			p->width = va_arg(p->arg, int);
			p->fmt_i++;
		}
		else
		{
			p->width = ft_atoi(fmt + p->fmt_i);
			p->fmt_i += ft_intmaxsize(p->width);
		}
		if (p->width < 0)
		{
			p->f_moins = 1;
			p->width *= -1;
		}
		return (1);
	}
	return (0);
}

static int	ft_printf_check_precision(t_print *p, const char *fmt)
{
	if (fmt[p->fmt_i] == '.' && fmt[p->fmt_i + 1] &&
			(ft_isdigit(fmt[p->fmt_i + 1]) || fmt[p->fmt_i + 1] == '.' ||
			fmt[p->fmt_i + 1] == '*'))
	{
		p->fmt_i++;
		if (fmt[p->fmt_i] == '*')
			ft_printf_precision_star(p, fmt);
		else
			ft_printf_precision(p, fmt);
		return (1);
	}
	else if (fmt[p->fmt_i] == '.')
	{
		p->fmt_i++;
		p->precision = -1;
		return (1);
	}
	return (0);
}

void		ft_printf_parse(t_print *p, const char *fmt)
{
	p->fmt_i++;
	while (fmt[p->fmt_i])
	{
		if (ft_printf_check_flags(p, fmt[p->fmt_i]))
			continue ;
		if (ft_printf_check_modifier(p, fmt))
			continue ;
		if (ft_printf_check_width(p, fmt))
			continue ;
		if (ft_printf_check_precision(p, fmt))
			continue ;
		if (ft_strchr("sSpidDoOuUxXcC%", fmt[p->fmt_i]))
		{
			p->conv = fmt[p->fmt_i];
			p->fmt_i++;
			break ;
		}
		else
			break ;
		p->fmt_i++;
	}
	ft_printf_conv(p);
}

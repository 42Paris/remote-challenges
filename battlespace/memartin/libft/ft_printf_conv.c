/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:28:35 by memartin          #+#    #+#             */
/*   Updated: 2020/02/18 17:24:17 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_setprefix(t_print *p)
{
	char	*prefix;

	if (p->f_zero && p->fmt[p->fmt_i])
	{
		if (p->width < 0)
			p->width = 0;
		prefix = ft_strnew(p->width);
		ft_memset(prefix, '0', p->width);
		p->width = 0;
	}
	else
		prefix = ft_strdup("");
	return (prefix);
}

static void		ft_printinvalid(t_print *p)
{
	p->width--;
	if (!p->f_moins)
		ft_printf_flags(p, ft_strdup(""), ft_setprefix(p));
	else if (!p->fmt[p->fmt_i])
		ft_printf_flags(p, ft_strdup(""), ft_strdup(""));
	else if (p->fmt[p->fmt_i + 1])
	{
		ft_printf_add_char(p, p->fmt);
		ft_printf_flags(p, ft_strdup(""), ft_strdup(""));
	}
}

void			ft_printf_conv(t_print *p)
{
	if (p->conv == 'i' || p->conv == 'd')
		ft_printf_di(p);
	else if (p->conv == 'D')
		ft_printf_majd(p);
	else if (p->conv == 'O')
		ft_printf_majo(p);
	else if (p->conv == 'U')
		ft_printf_maju(p);
	else if (p->conv == 'o' || p->conv == 'u' ||
			p->conv == 'x' || p->conv == 'X')
		ft_printf_oux(p);
	else if (p->conv == 'p')
		ft_printf_p(p);
	else if (p->conv == 'c' && !p->m_l)
		ft_printf_c(p);
	else if (p->conv == 'C' || (p->conv == 'c' && p->m_l))
		ft_printf_majc(p);
	else if (p->conv == 's' && !p->m_l)
		ft_printf_s(p);
	else if (p->conv == 'S' || (p->conv == 's' && p->m_l))
		ft_printf_majs(p);
	else if (p->conv == '%')
		ft_printf_modulo(p);
	else
		ft_printinvalid(p);
}

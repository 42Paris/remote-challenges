/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:18:33 by memartin          #+#    #+#             */
/*   Updated: 2020/02/19 14:57:24 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_setflags(t_print *p, char *s)
{
	if (p->f_moins)
		p->f_zero = 0;
	if (ft_strlen(s) == 1 && s[0] == '0' && !p->width)
	{
		p->f_hash = 0;
		p->f_zero = 0;
	}
	else
		p->width -= 2;
}

void			ft_printf_p(t_print *p)
{
	char	*tmp;

	tmp = ft_utoa_base(va_arg(p->arg, unsigned long int), 16);
	ft_setflags(p, tmp);
	if (tmp && ft_strlen(tmp) == 1 && tmp[0] == '0' && p->precision < 0)
	{
		ft_strdel(&tmp);
		ft_printf_flags(p, ft_strdup(""), ft_strdup("0x"));
	}
	else
		ft_printf_flags(p, tmp, ft_strdup("0x"));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:18:41 by memartin          #+#    #+#             */
/*   Updated: 2020/02/25 15:27:36 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_setprecision(t_print *p, char *s)
{
	if (p->precision < (int)ft_strlen(s) && p->precision > 0)
		s[p->precision] = '\0';
	if (p->precision == -1)
	{
		p->precision = 0;
		s[0] = '\0';
	}
}

static void		ft_setflags(t_print *p)
{
	if (p->f_moins)
		p->f_zero = 0;
}

void			ft_printf_s(t_print *p)
{
	char	*tmp;
	char	*s;

	s = va_arg(p->arg, char *);
	if (s)
		tmp = ft_strdup(s);
	else
		tmp = ft_strdup("(null)");
	ft_setflags(p);
	ft_setprecision(p, tmp);
	ft_printf_flags(p, tmp, ft_strdup(""));
}

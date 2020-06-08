/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_majo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:17:56 by memartin          #+#    #+#             */
/*   Updated: 2020/02/04 18:17:57 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_setflags(t_print *p, char *s)
{
	if (p->f_moins)
		p->f_zero = 0;
	if (ft_strlen(s) == 1 && s[0] == '0' && p->precision)
	{
		ft_strdel(&s);
		s = ft_strdup("");
	}
	if (p->f_hash)
		p->width--;
}

static char		*ft_setprefix(t_print *p)
{
	char	*ret;

	if (p->f_hash)
	{
		ret = ft_strnew(2);
		if (ret)
		{
			ret[0] = '0';
			return (ret);
		}
	}
	return (ft_strdup(""));
}

void			ft_printf_majo(t_print *p)
{
	char	*tmp;

	tmp = ft_utoa_base(va_arg(p->arg, unsigned long int), 8);
	ft_setflags(p, tmp);
	ft_printf_flags(p, tmp, ft_setprefix(p));
}

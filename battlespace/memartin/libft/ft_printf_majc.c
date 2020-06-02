/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_majc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:17:36 by memartin          #+#    #+#             */
/*   Updated: 2020/02/24 15:27:57 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_setflags(t_print *p, char c)
{
	if (p->f_moins)
		p->f_zero = 0;
	if (c == 0)
	{
		p->size++;
		p->width--;
	}
}

void			ft_printf_majc(t_print *p)
{
	int		c;
	int		ret;
	char	*tmp;

	tmp = ft_strnew(4);
	if (tmp)
	{
		c = va_arg(p->arg, int);
		if (c == 0)
		{
			ft_setflags(p, c);
			ft_printf_flags(p, ft_strdup(""), ft_strdup(""));
			ft_printf_buffer(p);
			ft_putchar(0);
		}
		else
		{
			ret = ft_printf_unicode((unsigned char*)tmp, c);
			tmp[ret] = '\0';
			ft_setflags(p, c);
			ft_printf_flags(p, tmp, ft_strdup(""));
		}
	}
}

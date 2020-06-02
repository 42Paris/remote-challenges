/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:51:34 by memartin          #+#    #+#             */
/*   Updated: 2020/02/25 15:04:18 by memartin         ###   ########.fr       */
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

static char		*ft_setprefix(t_print *p)
{
	char	*prefix;

	if (p->f_zero && p->width)
	{
		prefix = ft_strnew(p->width);
		ft_memset(prefix, '0', p->width);
		p->width = 0;
	}
	else
		prefix = ft_strdup("");
	return (prefix);
}

static void		ft_printnull(t_print *p, char c)
{
	ft_setflags(p, c);
	if (p->f_moins)
	{
		ft_printf_buffer(p);
		ft_putchar(0);
		ft_printf_flags(p, ft_strdup(""), ft_setprefix(p));
	}
	else
	{
		ft_printf_flags(p, ft_strdup(""), ft_setprefix(p));
		ft_printf_buffer(p);
		ft_putchar(0);
	}
}

void			ft_printf_c(t_print *p)
{
	char	*tmp;
	int		c;

	tmp = ft_strnew(2);
	if (tmp)
	{
		c = va_arg(p->arg, int);
		if (c == 0)
			ft_printnull(p, c);
		else
		{
			tmp[0] = c;
			ft_setflags(p, c);
			ft_printf_flags(p, tmp, ft_strdup(""));
		}
	}
}

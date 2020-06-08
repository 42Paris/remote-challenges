/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_majs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:18:01 by memartin          #+#    #+#             */
/*   Updated: 2020/02/24 15:27:49 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_setprefix(t_print *p, char *s)
{
	char	*prefix;

	if (p->f_zero && p->width > (int)ft_strlen(s))
	{
		prefix = ft_strnew(p->width - ft_strlen(s));
		ft_memset(prefix, '0', p->width - ft_strlen(s));
		p->width = 0;
	}
	else
		prefix = ft_strdup("");
	return (prefix);
}

static void		ft_setret(t_print *p, int *s, char *tmp)
{
	char	*buff;
	int		ret;
	int		len;

	ret = 0;
	len = 0;
	while (*s)
	{
		buff = ft_strnew(5);
		ret = ft_printf_unicode((unsigned char*)buff, *s);
		buff[ret] = '\0';
		len += ret;
		tmp = ft_joinfree(tmp, buff);
		if (len > p->precision && p->precision)
		{
			len -= ret;
			tmp[len] = '\0';
			break ;
		}
		s++;
	}
	ft_printf_flags(p, tmp, ft_setprefix(p, tmp));
}

void			ft_printf_majs(t_print *p)
{
	int		*s;

	s = va_arg(p->arg, int*);
	if (!s)
		ft_printf_flags(p, ft_strdup("(null)"), ft_strdup(""));
	else
		ft_setret(p, s, ft_strdup(""));
}

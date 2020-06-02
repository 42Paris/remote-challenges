/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:43:54 by memartin          #+#    #+#             */
/*   Updated: 2020/02/25 15:24:50 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_setnull(t_print *p, char *s)
{
	if (s && s[0] == '0' && p->precision == -1)
		if (p->conv == 'd' || p->conv == 'i' || p->conv == 'D' ||
				p->conv == 'x' || p->conv == 'X' || p->conv == 'u')
		{
			ft_strdel(&s);
			return (ft_strdup(""));
		}
	return (s);
}

static char		*ft_setprecision(t_print *p, char *s)
{
	char	*ret;

	if (p->conv != 'c' && p->conv != 'C' && p->conv != 's' && p->conv != 'S'
			&& p->precision > (int)ft_strlen(s))
	{
		ret = ft_strnew(p->precision - ft_strlen(s));
		if (ret)
		{
			ft_memset(ret, '0', p->precision - ft_strlen(s));
			return (ret);
		}
	}
	return (ft_strdup(""));
}

static char		*ft_setwidth(t_print *p, char *s, char *precision)
{
	char	*ret;
	int		len;

	len = p->width - ft_strlen(precision) - ft_strlen(s);
	if (len > 0)
	{
		ret = ft_strnew(len);
		if (ret)
		{
			if (!p->precision && p->f_zero)
				ft_memset(ret, '0', len);
			else
				ft_memset(ret, ' ', len);
			return (ret);
		}
	}
	return (ft_strdup(""));
}

void			ft_printf_flags(t_print *p, char *s, char *prefix)
{
	char	*precision;
	char	*width;
	char	*ret;

	s = ft_setnull(p, s);
	precision = ft_setprecision(p, s);
	width = ft_setwidth(p, s, precision);
	ret = ft_joinfree(precision, s);
	if (width && width[0] == '0')
	{
		ret = ft_joinfree(width, ret);
		ret = ft_joinfree(prefix, ret);
	}
	else
	{
		ret = ft_joinfree(prefix, ret);
		if (p->f_moins)
			ret = ft_joinfree(ret, width);
		else
			ret = ft_joinfree(width, ret);
	}
	p->size += ft_strlen(ret);
	ft_printf_add_conv(p, ret);
}

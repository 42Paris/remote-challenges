/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_oux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:18:26 by memartin          #+#    #+#             */
/*   Updated: 2020/02/25 15:27:35 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_setflags(t_print *p, char *s)
{
	if (p->f_moins)
		p->f_zero = 0;
	if (ft_strlen(s) == 1 && s[0] == '0')
	{
		if (p->precision || (p->conv == 'o' && p->precision == -1 && !p->f_pre))
			s = ft_strdup("");
		if (p->conv != 'o' || (p->conv == 'o' && !p->precision))
			p->f_hash = 0;
	}
	if ((p->conv == 'x' || p->conv == 'X') && p->f_hash)
		p->width -= 2;
	if (p->conv == 'o' && p->f_hash)
	{
		p->width--;
		p->precision--;
	}
}

static char		*ft_setprefix(t_print *p)
{
	char	*ret;

	if (p->conv == 'o' && p->f_hash)
	{
		ret = ft_strnew(2);
		if (ret)
		{
			ret[0] = '0';
			return (ret);
		}
	}
	if ((p->conv == 'x' || p->conv == 'X') && p->f_hash)
	{
		ret = ft_strnew(3);
		if (ret)
		{
			ret[0] = '0';
			ret[1] = p->conv;
			return (ret);
		}
	}
	return (ft_strdup(""));
}

static int		ft_setbase(t_print *p)
{
	if (p->conv == 'o')
		return (8);
	if (p->conv == 'p' || p->conv == 'x' || p->conv == 'X')
		return (16);
	return (10);
}

static void		ft_capitalize(t_print *p, char *s)
{
	int		i;

	i = 0;
	if (p->conv == 'X')
	{
		while (s[i])
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 32;
			i++;
		}
	}
}

void			ft_printf_oux(t_print *p)
{
	char	*tmp;
	int		base;

	base = ft_setbase(p);
	if (p->m_ll)
		tmp = ft_utoa_base(va_arg(p->arg, unsigned long long), base);
	else if (p->m_l)
		tmp = ft_utoa_base(va_arg(p->arg, unsigned long), base);
	else if (p->m_j)
		tmp = ft_utoa_base(va_arg(p->arg, size_t), base);
	else if (p->m_z)
		tmp = ft_utoa_base(va_arg(p->arg, uintmax_t), base);
	else if (p->m_h)
		tmp = ft_utoa_base((unsigned short)va_arg(p->arg, unsigned int), base);
	else if (p->m_hh)
		tmp = ft_utoa_base((unsigned char)va_arg(p->arg, unsigned int), base);
	else
		tmp = ft_utoa_base(va_arg(p->arg, unsigned int), base);
	ft_setflags(p, tmp);
	ft_capitalize(p, tmp);
	ft_printf_flags(p, tmp, ft_setprefix(p));
}

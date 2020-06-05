/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:17:28 by memartin          #+#    #+#             */
/*   Updated: 2020/02/25 15:04:42 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_setflags(t_print *p)
{
	if (p->f_moins && p->f_zero)
		p->f_zero = 0;
	if (p->f_plus || p->f_space || p->n_neg)
	{
		p->width--;
		if (p->f_space && p->n_neg)
			p->f_space = 0;
		if (p->f_plus && p->n_neg)
			p->f_plus = 0;
	}
}

static char		*ft_setneg(t_print *p, char *s)
{
	char	*ret;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (s && s[i] == '-')
	{
		ret = ft_strnew(ft_strlen(s) - 1);
		p->n_neg = 1;
		i++;
		while (s[i])
			ret[j++] = s[i++];
		ft_strdel(&s);
		return (ret);
	}
	return (s);
}

static char		*ft_setprefix(t_print *p)
{
	char	*ret;

	if (p->f_space || p->f_plus || p->n_neg)
	{
		ret = ft_strnew(2);
		if (ret)
		{
			if (p->n_neg)
				ret[0] = '-';
			else if (p->f_plus)
				ret[0] = '+';
			else if (p->f_space)
				ret[0] = ' ';
			return (ret);
		}
	}
	return (ft_strdup(""));
}

void			ft_printf_di(t_print *p)
{
	char	*tmp;

	if (p->m_ll)
		tmp = ft_ltoa(va_arg(p->arg, long long int));
	else if (p->m_l)
		tmp = ft_ltoa(va_arg(p->arg, long int));
	else if (p->m_j)
		tmp = ft_ltoa(va_arg(p->arg, size_t));
	else if (p->m_z)
		tmp = ft_ltoa(va_arg(p->arg, intmax_t));
	else if (p->m_h)
		tmp = ft_ltoa((short)va_arg(p->arg, int));
	else if (p->m_hh)
		tmp = ft_ltoa((char)va_arg(p->arg, int));
	else
		tmp = ft_ltoa(va_arg(p->arg, int));
	tmp = ft_setneg(p, tmp);
	ft_setflags(p);
	ft_printf_flags(p, tmp, ft_setprefix(p));
}

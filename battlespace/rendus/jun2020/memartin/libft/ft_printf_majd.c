/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_majd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:17:43 by memartin          #+#    #+#             */
/*   Updated: 2020/02/24 15:26:41 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_setflags(t_print *p, char *s)
{
	if ((p->f_moins && p->f_zero) || (s && s[0] == '0'))
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

static void		*ft_setneg(t_print *p, char *s)
{
	char	*ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
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

void			ft_printf_majd(t_print *p)
{
	char	*tmp;

	tmp = ft_ltoa(va_arg(p->arg, long long));
	tmp = ft_setneg(p, tmp);
	ft_setflags(p, tmp);
	ft_printf_flags(p, tmp, ft_setprefix(p));
}

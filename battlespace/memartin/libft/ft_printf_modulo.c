/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_modulo.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:18:18 by memartin          #+#    #+#             */
/*   Updated: 2020/02/04 18:18:19 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_setflags(t_print *p)
{
	if (p->f_moins)
		p->f_zero = 0;
	p->precision = 0;
}

void			ft_printf_modulo(t_print *p)
{
	char	*tmp;

	tmp = ft_strnew(2);
	if (tmp)
	{
		tmp[0] = '%';
		ft_setflags(p);
		ft_printf_flags(p, tmp, ft_strdup(""));
	}
}

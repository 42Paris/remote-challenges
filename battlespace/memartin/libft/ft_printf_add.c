/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:25:31 by memartin          #+#    #+#             */
/*   Updated: 2020/02/20 14:40:48 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_printf_add_char(t_print *p, const char *fmt)
{
	p->result[p->buff_i] = fmt[p->fmt_i];
	p->buff_i++;
	p->result[p->buff_i] = '\0';
	p->fmt_i++;
	p->size++;
}

void		ft_printf_add_conv(t_print *p, char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (p->buff_i >= 3999)
			ft_printf_buffer(p);
		p->result[p->buff_i] = s[i];
		i++;
		p->buff_i++;
	}
	ft_strdel(&s);
}

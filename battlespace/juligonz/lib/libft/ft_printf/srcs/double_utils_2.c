/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/27 16:58:21 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/12 16:43:31 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_double_width(t_manager *p, int nb_char)
{
	int i;

	if (p->f.zero)
		return ;
	i = p->width;
	while (i > nb_char)
	{
		write_buffer(p, " ", 1);
		i--;
	}
}

void	put_double_zero(t_manager *p, int nb_char)
{
	int i;

	if (!p->f.zero)
		return ;
	i = p->width;
	while (i > nb_char)
	{
		write_buffer(p, "0", 1);
		i--;
	}
}

int		trailing_zero(long double mantis, int precision)
{
	int		i;
	int		new_precision;
	char	c;

	i = precision;
	new_precision = 0;
	while (i--)
	{
		mantis -= (int)mantis;
		mantis *= 10;
		c = (int)mantis;
		if (c)
			new_precision = precision - i;
	}
	return (new_precision);
}

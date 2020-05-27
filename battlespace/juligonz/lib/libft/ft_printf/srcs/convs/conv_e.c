/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_e.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:47:35 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/12 17:16:10 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conv_e(va_list args, t_manager *p)
{
	long double n;

	if (p->f.l_uppercase)
		n = va_arg(args, long double);
	else
		n = va_arg(args, double);
	if (is_valid_float(n, p))
		put_e(n, p);
}

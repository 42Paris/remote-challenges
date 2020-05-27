/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_len_modifier.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 14:52:15 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/13 11:15:40 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <inttypes.h>

int64_t		cast_signed(t_manager *p, va_list args)
{
	if (p->f.hh)
		return ((char)va_arg(args, int));
	if (p->f.h)
		return ((short)va_arg(args, int));
	if (p->f.l)
		return (va_arg(args, long));
	if (p->f.ll)
		return (va_arg(args, long long));
	if (p->f.j)
		return (va_arg(args, intmax_t));
	return (va_arg(args, int));
}

uint64_t	cast_unsigned(t_manager *p, va_list args)
{
	if (p->f.hh)
		return ((unsigned char)va_arg(args, unsigned int));
	if (p->f.h)
		return ((unsigned short)va_arg(args, unsigned int));
	if (p->f.l)
		return (va_arg(args, unsigned long));
	if (p->f.ll)
		return (va_arg(args, unsigned long long));
	if (p->f.j)
		return (va_arg(args, uintmax_t));
	return (va_arg(args, unsigned int));
}

void		*cast_ptr(t_manager *p, va_list args)
{
	if (p->f.hh)
		return ((char *)va_arg(args, int *));
	if (p->f.h)
		return ((short *)va_arg(args, int *));
	if (p->f.l)
		return (va_arg(args, long *));
	if (p->f.ll)
		return (va_arg(args, long long *));
	return (va_arg(args, int *));
}

wint_t		cast_c(t_manager *p, va_list args)
{
	if (p->f.l)
		return (va_arg(args, wint_t));
	return (va_arg(args, int));
}

wchar_t		*cast_s(t_manager *p, va_list args)
{
	if (p->f.l)
		return (va_arg(args, wchar_t *));
	return ((wchar_t *)va_arg(args, char *));
}

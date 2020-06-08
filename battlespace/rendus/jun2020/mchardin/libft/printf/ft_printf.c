/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:56:10 by mchardin          #+#    #+#             */
/*   Updated: 2019/12/10 09:46:58 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_noflag(const char chr, va_list *ap, char *cz)
{
	char *str;

	if (chr == 'd' || chr == 'i')
		return (ft_itoa(va_arg(*ap, int)));
	else if (chr == 's')
	{
		str = va_arg(*ap, char*);
		return (ft_strdup(str ? str : "(null)"));
	}
	else if (chr == 'c')
		return (ft_char_to_str(va_arg(*ap, int), cz));
	else if (chr == '%')
		return (ft_char_to_str('%', cz));
	else if (chr == 'p')
		return (ft_point(va_arg(*ap, uintptr_t)));
	else if (chr == 'u' || chr == 'x' || chr == 'X')
		return (ft_unsign_hexa(va_arg(*ap, int), chr));
	else
		return (0);
}

char		*ft_flag(const char *str, va_list *ap, int *i, char *cz)
{
	int		j;
	char	*to_conv;
	t_flags conv;

	j = -1;
	while (++j < 3)
		conv.flaglist[j] = 0;
	conv.size = 0;
	conv.precision = 0;
	if (!(ft_addflags(&conv, str, i, ap)))
		return (0);
	if (!(to_conv = ft_noflag(str[*i], ap, cz)))
		return (0);
	*i = *i + 1;
	if (*cz)
	{
		*cz = (conv.flaglist[0] == 1 ? 2 : *cz);
		*cz = (conv.size < 1 ? *cz : *cz + 2);
	}
	return (ft_conversion(to_conv, &conv, str[*i - 1]));
}

char		*ft_arg(const char *str, va_list *ap, int *i, char *cz)
{
	*i = *i + 1;
	if (ft_isconv(str[*i]) == 1)
	{
		*i = *i + 1;
		return (ft_noflag(str[*i - 1], ap, cz));
	}
	else if (ft_isconv(str[*i]) >= 2)
		return (ft_flag(str, ap, i, cz));
	return (0);
}

int			ft_str(const char *str, t_list **lst, va_list *ap)
{
	int		i;
	int		j;
	t_list	*new;
	char	cz;

	i = 0;
	while (str[i])
	{
		cz = 0;
		if (str[i] != '%')
		{
			j = ft_len_c(&str[i], '%');
			if (!(new = ft_lstnew(ft_strct(ft_substr(str, i, j), cz))))
				return (0);
			ft_lstadd_back(lst, new);
			i += j;
		}
		else
		{
			if (!(new = ft_lstnew(ft_strct(ft_arg(str, ap, &i, &cz), cz))))
				return (0);
			ft_lstadd_back(lst, new);
		}
	}
	return (1);
}

int			ft_printf(const char *str, ...)
{
	t_list	*lst;
	va_list	ap;

	lst = 0;
	va_start(ap, str);
	if (!(ft_str(str, &lst, &ap)))
	{
		ft_lstclear(&lst, &ft_delcontent);
		return (-1);
	}
	va_end(ap);
	return (ft_print_lst(1, lst));
}

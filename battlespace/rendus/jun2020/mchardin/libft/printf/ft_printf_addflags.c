/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_addflags.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 15:30:20 by mchardin          #+#    #+#             */
/*   Updated: 2020/04/22 22:17:28 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_analyse_nb(int nb, char chr, t_flags *conv)
{
	if (chr == '.' && nb == 0)
		return (0);
	else if (chr == '.' && nb < 0)
		return (-1);
	else if (nb < 0)
	{
		conv->flaglist[0] = 1;
		return (-nb);
	}
	else
		return (nb);
}

int		ft_flagsize(const char *str, int *i, va_list *ap, t_flags *conv)
{
	int		nb;
	int		len;
	char	*str_nb;

	len = 0;
	if (str[*i] == '*')
	{
		nb = va_arg(*ap, int);
		*i = *i + 1;
		len++;
	}
	else
	{
		while (ft_isdigit(str[*i]))
		{
			*i = *i + 1;
			len++;
		}
		str_nb = ft_substr(str, *i - len, len);
		nb = ft_atoi(str_nb);
		ft_freez((void **)&str_nb);
	}
	return (ft_analyse_nb(nb, str[*i - len - 1], conv));
}

int		ft_addflags(t_flags *conv, const char *str, int *i, va_list *ap)
{
	while (str[*i] == '0' || str[*i] == '-')
	{
		if (str[*i] == '-')
			conv->flaglist[0] = 1;
		else
			conv->flaglist[1] = 1;
		*i = *i + 1;
	}
	if (ft_isconv(str[*i]) == 3)
		conv->size = ft_flagsize(str, i, ap, conv);
	if (str[*i] == '.')
	{
		conv->flaglist[2] = 1;
		*i = *i + 1;
		if (ft_isconv(str[*i]) == 3 || str[*i] == '0')
			conv->precision = ft_flagsize(str, i, ap, conv);
	}
	return (ft_isconv(str[*i]) == 1 ? 1 : 0);
}

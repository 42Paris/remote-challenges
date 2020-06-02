/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 09:52:28 by mchardin          #+#    #+#             */
/*   Updated: 2020/03/03 16:44:41 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

t_cont		*ft_strct(char *str, char czero)
{
	t_cont	*cont;

	if (!(cont = malloc(sizeof(t_cont))))
		return (0);
	cont->str = str;
	cont->czero = czero;
	return (cont);
}

char		*ft_convert_string(char *to_conv, t_flags *conv, char c)
{
	char	*pre;

	if (conv->flaglist[2] == 1 && c == 's')
		pre = ft_substr(to_conv, 0, conv->precision);
	else
		pre = ft_strdup(to_conv);
	return (pre);
}

int			ft_isconv(char c)
{
	if (c == 's' || c == 'c' || c == 'd' || c == 'i' || c == '%'
		|| c == 'X' || c == 'x' || c == 'p' || c == 'u')
		return (1);
	else if (c == '.' || c == '0' || c == '-')
		return (2);
	else if ((c > '0' && c <= '9') || c == '*')
		return (3);
	return (0);
}

char		*ft_char_to_str(char c, char *cz)
{
	char	*cpy;

	if (!(cpy = malloc(sizeof(char) * 2)))
		return (0);
	cpy[0] = c;
	cpy[1] = 0;
	if (c == 0)
		*cz = 1;
	return (cpy);
}

int			ft_len_c(const char *s, int c)
{
	int i;

	i = 0;
	while (s && s[i] && s[i] != c)
		i++;
	return (i);
}

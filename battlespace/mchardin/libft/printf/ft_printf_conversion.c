/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conversion.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:00:29 by mchardin          #+#    #+#             */
/*   Updated: 2020/03/02 15:47:52 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_fill_z(char *str, int z, char c)
{
	char	*new;
	char	*tmp_new;
	int		i;

	i = -1;
	if (z < 0)
		z = 0;
	if (!(new = malloc(sizeof(char) * (ft_len_c(str, 0) + z + 1))))
		return (0);
	tmp_new = new;
	if ((c != 's' && c != 'c' && c != '%') && str
		&& (str[i + 1] == '-' || (str[i + 1] == '0' && str[i + 2] == 'x')))
	{
		*new++ = str[++i];
		if (str[i] == 'x' && i++)
			*new++ = str[i];
	}
	while (z-- > 0)
		*new++ = '0';
	while (str && str[++i])
		*new++ = str[i];
	*new = 0;
	return (tmp_new);
}

char	*ft_fill_sp(char *str, int sp_b, int sp_a)
{
	char	*new;
	char	*tmp_new;
	int		i;

	sp_b = (sp_b > 0 ? sp_b : 0);
	sp_a = (sp_a > 0 ? sp_a : 0);
	i = -1;
	if (!(new = malloc(sizeof(char) * (ft_len_c(str, 0) + sp_b + sp_a + 1))))
		return (0);
	tmp_new = new;
	while (sp_b-- > 0)
		*new++ = ' ';
	while (str && str[++i])
		*new++ = str[i];
	while (sp_a-- > 0)
		*new++ = ' ';
	*new = 0;
	return (tmp_new);
}

char	*ft_fill_pre(char *str, t_flags *conv, char c)
{
	if (conv->flaglist[2] == 1 && (c == 's' || c == 'c' || c == '%'))
		return (ft_convert_string(str, conv, c));
	else if (conv->flaglist[2] == 1 && str[0] == '-')
		return (ft_fill_z(str, conv->precision - ft_len_c(str, 0) + 1, c));
	else
		return (ft_fill_z(str, conv->precision - ft_len_c(str, 0), c));
}

char	*ft_fill_p(char *str, t_flags *conv, char c)
{
	char	*pre;
	char	*new_str;
	int		len;

	if (!(pre = ft_fill_pre(str, conv, c)))
		return (0);
	len = ft_len_c(pre, 0);
	if (conv->size <= len)
		new_str = ft_strdup(pre);
	else if (conv->flaglist[0] == 1)
		new_str = ft_fill_sp(pre, 0, conv->size - len);
	else if (conv->flaglist[1] == 1 && (conv->flaglist[2] == 0
		|| conv->precision < 0 || c == 's' || c == 'c' || c == '%'))
		new_str = ft_fill_z(pre, conv->size - len, c);
	else
		new_str = ft_fill_sp(pre, conv->size - len, 0);
	ft_freez((void **)&pre);
	return (new_str);
}

char	*ft_conversion(char *to_conv, t_flags *conv, char c)
{
	char	*new_str;

	if (conv->precision == 0 && conv->flaglist[2] == 1
		&& to_conv[0] == '0' && c != 'c' && c != 's' && c != '%')
	{
		new_str = ft_fill_sp(0, conv->size, 0);
		ft_freez((void **)&to_conv);
		return (new_str);
	}
	else if (conv->size == 1 && c != 'c' && c != 's' && c != '%')
		conv->size = 0;
	new_str = ft_fill_p(to_conv, conv, c);
	ft_freez((void **)&to_conv);
	return (new_str);
}

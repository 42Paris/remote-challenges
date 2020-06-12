/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:12:36 by roalvare          #+#    #+#             */
/*   Updated: 2019/11/16 09:37:03 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	if_zero(t_conv *conv, t_list *lst)
{
	if (!(conv->width > lstc_size(lst)))
		return (0);
	if (!(has_flag(conv->flag, ZERO)))
		return (0);
	if (!(!has_flag(conv->flag, MINUS)))
		return (0);
	if (!(conv->precision < 0))
		return (0);
	return (1);
}

t_list		*c_int(t_conv *conv)
{
	t_list	*lst;
	t_node	*node;
	int		len_m;
	char	*data;

	if (!(data = ft_itoa(*((int*)conv->content))))
		return (NULL);
	if (!(lst = s_in_lst(data, conv)))
		return (NULL);
	node = lst->content;
	if (conv->precision == 0 && *node->str == '0')
		reset_s(lst);
	len_m = has_sign(lst) ? lstc_size(lst) - 1 : lstc_size(lst);
	if (conv->precision > len_m && conv->precision > 0)
		lst = pad_zero(lst, conv->precision - len_m);
	if (if_zero(conv, lst))
		lst = pad_zero(lst, conv->width - lstc_size(lst));
	if (lst == NULL)
		return (NULL);
	return (lst);
}

t_list		*c_uint(t_conv *conv)
{
	t_list			*lst;
	t_node			*node;
	unsigned int	content;
	char			*data;

	lst = NULL;
	data = NULL;
	content = *((unsigned int*)conv->content);
	if (conv->type == UNSIGNED)
		data = ft_utoa(content, "0123456789");
	else if (conv->type == HEXA_L)
		data = ft_utoa(content, "0123456789abcdef");
	else if (conv->type == HEXA_U)
		data = ft_utoa(content, "0123456789ABCDEF");
	if (!(lst = s_in_lst(data, conv)))
		return (NULL);
	node = lst->content;
	if (conv->precision == 0 && *node->str == '0')
		reset_s(lst);
	if (conv->precision > lstc_size(lst) && conv->precision > 0)
		lst = pad_zero(lst, conv->precision - lstc_size(lst));
	if (if_zero(conv, lst))
		lst = pad_zero(lst, conv->width - lstc_size(lst));
	return (lst);
}

t_list		*c_pointer(t_conv *conv)
{
	t_list			*lst;
	t_list			*elmt;
	t_node			*node;
	unsigned long	content;
	char			*pre;

	lst = NULL;
	content = *((unsigned long*)conv->content);
	if (!(lst = s_in_lst(ft_utoa(content, "0123456789abcdef"), conv)))
		return (NULL);
	if (!(pre = ft_strdup("0x")))
		return (lst);
	if (!(elmt = create_node(pre, 2)))
		return (lst);
	ft_lstadd_front(&lst, elmt);
	node = lst->content;
	if (conv->precision == 0 && *node->str == '0')
		reset_s(lst);
	if (conv->precision > lstc_size(lst) && conv->precision > 0)
		lst = pad_zero(lst, conv->precision - lstc_size(lst));
	if (if_zero(conv, lst))
		lst = pad_zero(lst, conv->width - lstc_size(lst));
	return (lst);
}

char		*ft_utoa(unsigned long nbr, char *base)
{
	char			*str;
	int				len;
	unsigned long	tmp;
	int				i;
	unsigned long	len_b;

	str = NULL;
	len = 0;
	tmp = nbr;
	i = 0;
	len_b = ft_strlen(base);
	while (tmp != 0 || len == 0)
	{
		len++;
		tmp /= len_b;
	}
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (NULL);
	while (nbr != 0 || i == 0)
	{
		str[len - 1 - i] = base[nbr % len_b];
		nbr /= len_b;
		i++;
	}
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syndraum <syndraum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 17:40:43 by roalvare          #+#    #+#             */
/*   Updated: 2019/11/15 18:51:34 by syndraum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putstr_n(char *str, int n)
{
	if (n >= 0)
	{
		while (n != 0)
		{
			ft_putchar_fd(*str, 1);
			str++;
			n--;
		}
	}
}

int			ft_printf(const char *str, ...)
{
	va_list l_arg;
	t_list	*lst;
	char	*output;
	int		len;

	va_start(l_arg, str);
	if (!(lst = get_list((char*)str, &l_arg)))
		return (-1);
	va_end(l_arg);
	len = lstc_size(lst);
	output = lst_to_s(lst);
	ft_lstclear(&lst, &free_node);
	if (output == NULL)
		return (-1);
	ft_putstr_n(output, len);
	free(output);
	return (len);
}

static void	*add_string(char *cursor, t_list **lst)
{
	int		nbr;
	char	*to_past;
	t_list	*elmt;

	nbr = ft_strchr(cursor, '%') + 1 - cursor;
	if (!(to_past = ft_calloc(nbr, sizeof(char))))
		return (NULL);
	ft_strlcpy(to_past, cursor, nbr);
	if ((elmt = create_node(to_past, ft_strlen(to_past))))
		ft_lstadd_back(lst, elmt);
	return (elmt);
}

t_list		*get_list(char *str, va_list *l_arg)
{
	t_conv	*conv;
	t_list	*lst;
	t_list	*elmt;
	char	*cursor;

	conv = NULL;
	lst = NULL;
	cursor = (char*)str;
	while (ft_strchr(cursor, '%'))
	{
		elmt = add_string(cursor, &lst);
		cursor = ft_strchr(cursor, '%');
		if ((conv = creat_conv(&cursor, l_arg)))
			ft_lstadd_back(&lst, get_convert(conv));
		free_conv(conv);
	}
	if ((elmt = create_node(ft_strdup(cursor), ft_strlen(cursor))))
		ft_lstadd_back(&lst, elmt);
	return (lst);
}

t_list		*get_convert(t_conv *conv)
{
	t_list	*lst;

	if (conv == NULL)
		return (NULL);
	if (is_int(conv->type))
		lst = c_int(conv);
	else if (is_uint(conv->type))
		lst = c_uint(conv);
	else if (conv->type == STRING || conv->type == CHARACTER)
		lst = c_char(conv);
	else if (conv->type == POINTEUR)
		lst = (c_pointer(conv));
	else if (conv->type == POURCENT)
		return (c_pourcent());
	else
		return (NULL);
	lst = set_padding(lst, conv);
	return (lst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syndraum <syndraum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:28:52 by syndraum          #+#    #+#             */
/*   Updated: 2019/11/15 19:25:14 by syndraum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*set_padding(t_list *lst, t_conv *conv)
{
	int		i;
	int		len;
	char	*str;
	t_list	*elmt;

	i = -1;
	len = 0;
	if (conv == NULL)
		return (lst);
	if (conv->width > lstc_size(lst))
	{
		len = conv->width - lstc_size(lst);
		if (!(str = ft_calloc(len + 1, sizeof(char))))
			return (lst);
		while (++i < len)
			str[i] = ' ';
		if (!(elmt = create_node(str, ft_strlen(str))))
			return (lst);
		if (has_flag(conv->flag, MINUS))
			ft_lstadd_back(&lst, elmt);
		else
			ft_lstadd_front(&lst, elmt);
	}
	return (lst);
}

void	reset_s(t_list *lst)
{
	t_list	*cursor;
	t_node	*node;

	cursor = lst;
	while (cursor != NULL)
	{
		node = (t_node*)cursor->content;
		node->len = 0;
		cursor = cursor->next;
	}
}

t_list	*pad_zero(t_list *lst, int len)
{
	int		i;
	char	*str;
	t_list	*elmt;

	i = -1;
	if (!(str = ft_calloc(len + 1, sizeof(char))))
		return (lst);
	while (++i < len)
		str[i] = '0';
	if (has_sign(lst))
		add_indlst(&lst, str, 1);
	else if ((elmt = create_node(str, ft_strlen(str))))
		ft_lstadd_front(&lst, elmt);
	return (lst);
}

void	set_flag(t_conv *conv, t_flag f)
{
	t_flag	*flag;
	t_list	*elmt;

	if ((flag = malloc(sizeof(t_flag))))
	{
		*flag = f;
		if ((elmt = ft_lstnew(flag)))
			ft_lstadd_back(&(conv->flag), elmt);
		else
			free_content(flag);
	}
}

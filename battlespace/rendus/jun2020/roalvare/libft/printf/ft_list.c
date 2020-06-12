/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syndraum <syndraum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:33:52 by syndraum          #+#    #+#             */
/*   Updated: 2019/11/15 19:21:22 by syndraum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			lstc_size(t_list *lst)
{
	int		len;
	t_node	*node;

	len = 0;
	if (lst == NULL)
		return (0);
	while (lst)
	{
		if (!(node = (t_node*)lst->content))
			return (0);
		len += node->len;
		lst = lst->next;
	}
	return (len);
}

static void	*int_lst(t_list *lst, char *str)
{
	char	*sep;
	t_list	*elmt;
	char	*cursor;

	cursor = str;
	if (!(sep = ft_calloc(2, sizeof(char))))
		return (NULL);
	*sep = '-';
	if (!(elmt = create_node(sep, 1)))
		return (NULL);
	ft_lstadd_back(&lst, elmt);
	cursor++;
	if (!(sep = ft_strdup(cursor)))
		return (lst);
	if ((elmt = create_node(sep, ft_strlen(sep))))
		ft_lstadd_back(&lst, elmt);
	return (lst);
}

t_list		*s_in_lst(char *str, t_conv *conv)
{
	t_list	*lst;
	t_list	*elmt;

	lst = NULL;
	if (is_int(conv->type) && *str == '-')
	{
		if (!(lst = int_lst(lst, str)))
			return (NULL);
		free(str);
	}
	else if (conv->type == CHARACTER)
	{
		if ((elmt = create_node(str, 1)))
			ft_lstadd_back(&lst, elmt);
	}
	else if ((elmt = create_node(str, ft_strlen(str))))
		ft_lstadd_back(&lst, elmt);
	return (lst);
}

char		*lst_to_s(t_list *lst)
{
	char	*str;
	int		i;
	int		len;
	t_node	*node;

	i = 0;
	if (lst == NULL)
		return (NULL);
	len = lstc_size(lst);
	if (!(str = ft_calloc(sizeof(char), (len + 1))))
		return (NULL);
	while (lst != NULL && lst->content != NULL)
	{
		node = (t_node*)lst->content;
		ft_strlcat(str + i, node->str, node->len + 1);
		i += node->len;
		lst = lst->next;
	}
	return (str);
}

t_list		*add_indlst(t_list **lst, void *content, int index)
{
	t_list	*cursor;
	t_list	*elmt;
	int		i;

	cursor = *lst;
	if (content == NULL)
		return (*lst);
	if (!(elmt = create_node(content, ft_strlen(content))))
		return (*lst);
	if (index == 0)
		ft_lstadd_front(lst, elmt);
	else
	{
		i = -1;
		while (++i < index - 1)
			cursor = cursor->next;
		elmt->next = cursor->next;
		cursor->next = elmt;
	}
	return (*lst);
}

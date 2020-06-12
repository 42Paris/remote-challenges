/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:11:54 by hben-yah          #+#    #+#             */
/*   Updated: 2019/06/18 11:24:00 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del_all_list(t_list **lst)
{
	t_list *todel;

	if (lst)
		while (*lst)
		{
			todel = *lst;
			*lst = (*lst)->next;
			free(todel->content);
			free(todel);
		}
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlist;
	t_list	*dlist;

	if (!lst || !f || !(newlist = ft_lstnew(lst->content, lst->content_size)))
		return (NULL);
	newlist = f(newlist);
	dlist = newlist;
	while ((lst = lst->next))
	{
		if (!(dlist->next = ft_lstnew(lst->content, lst->content_size)))
		{
			del_all_list(&newlist);
			return (NULL);
		}
		dlist = dlist->next;
		dlist = f(dlist);
	}
	return (newlist);
}

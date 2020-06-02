/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 18:26:47 by mchardin          #+#    #+#             */
/*   Updated: 2019/11/13 10:51:57 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*newlst;

	if (lst == 0)
		return (0);
	if (!(newlst = ft_lstnew(f ? f(lst->content) : lst->content)))
		return (0);
	start = newlst;
	while (lst->next != 0)
	{
		if (f)
			newlst->next = ft_lstnew(f(lst->next->content));
		else
			newlst->next = ft_lstnew(lst->next->content);
		if (!(newlst->next))
		{
			ft_lstclear(&start, del);
			return (0);
		}
		newlst = newlst->next;
		lst = lst->next;
	}
	return (start);
}

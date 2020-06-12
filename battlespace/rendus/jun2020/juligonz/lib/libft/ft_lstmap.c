/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:15:30 by juligonz          #+#    #+#             */
/*   Updated: 2019/10/11 19:04:23 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*new_list;
	t_list	*iterator;

	if (!lst)
		return (NULL);
	iterator = ft_lstnew(f(lst->content));
	new_list = iterator;
	while (lst->next != NULL)
	{
		lst = lst->next;
		iterator->next = ft_lstnew(f(lst->content));
		iterator = iterator->next;
	}
	return (new_list);
}

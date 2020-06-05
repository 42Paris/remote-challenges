/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraylist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/16 13:49:27 by hben-yah          #+#    #+#             */
/*   Updated: 2018/09/06 21:10:07 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		al_index_of(t_arlist *al, void *content, size_t content_size)
{
	t_list	*list;
	size_t	i;

	i = 0;
	if (!al->list)
		return (-1);
	list = al->list;
	while (list && ft_memcmp(content, list->content,
			content_size > list->content_size ?
				content_size : list->content_size) != 0 && ++i)
		list = list->next;
	return (!list ? -1 : (int)i);
}

void	*al_get(t_arlist *al, int i)
{
	t_list *list;

	if ((size_t)i >= al->length)
		return (NULL);
	list = al->list;
	while (list && i-- > 0)
		list = list->next;
	return (list ? list->content : NULL);
}

int		al_add(t_arlist *al, void *content, size_t content_size)
{
	t_list *new;
	t_list *list;

	if (!(new = ft_lstnew(content, content_size)))
		return (0);
	if (!al->list)
		al->list = new;
	else
	{
		list = al->list;
		while (list->next)
			list = list->next;
		list->next = new;
	}
	++(al->length);
	return (1);
}

void	*al_remove(t_arlist *al, int i)
{
	t_list	*list;
	t_list	*rem;
	void	*ret;

	if ((size_t)i > al->length - 1 || al->length == 0 || i < 0)
		return (NULL);
	if (i == 0)
	{
		rem = al->list;
		al->list = al->list->next;
	}
	else
	{
		list = al->list;
		while (i-- > 1)
			list = list->next;
		rem = list->next;
		list->next = list->next->next;
	}
	ret = rem->content;
	rem->content = NULL;
	ft_memdel((void **)&rem);
	--(al->length);
	return (ret);
}

void	al_del(t_arlist **al)
{
	if (al)
	{
		while ((*al)->length > 0)
			free(al_remove(*al, 0));
		ft_memdel((void **)al);
	}
}

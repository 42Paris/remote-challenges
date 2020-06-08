/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:34:34 by hben-yah          #+#    #+#             */
/*   Updated: 2019/07/20 16:17:27 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ht_itemadd(t_hashitem **tail, char *key, void *data, size_t size)
{
	t_hashitem *new;

	if (!(new = (t_hashitem *)ft_memalloc(sizeof(t_hashitem)))
		|| !(new->key = ft_strdup(key)))
	{
		ft_memdel((void **)&new);
		return (1);
	}
	new->size = size;
	new->data = data;
	new->next = *tail;
	*tail = new;
	return (0);
}

void	ht_itemdel(t_hashitem **head, void (*del)(void *, size_t))
{
	t_hashitem	*todel;

	if (head && *head)
	{
		todel = *head;
		*head = (*head)->next;
		free(todel->key);
		del(todel->data, todel->size);
		free(todel);
	}
}

void	ht_tabclear(t_hashtab *ht, void (*del)(void *, size_t))
{
	size_t		i;

	if (ht)
	{
		i = 0;
		while (i < ht->size)
		{
			while (ht->array[i])
				ht_itemdel(&ht->array[i], del);
			++i;
		}
	}
}

void	ht_tabdel(t_hashtab **ht, void (*del)(void *, size_t))
{
	if (ht && *ht)
	{
		ht_tabclear(*ht, del);
		ft_memdel((void **)&(*ht)->array);
		free(*ht);
		*ht = NULL;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:40:03 by hben-yah          #+#    #+#             */
/*   Updated: 2019/07/20 16:14:02 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ht_hash(char *key, size_t size)
{
	size_t	hash;

	hash = 0;
	if (key)
	{
		while (*key)
			hash = (hash + *(key++)) % size;
	}
	return (hash);
}

t_hashtab	*ht_new(size_t size)
{
	t_hashtab	*ht;

	if (size < 1
		|| !(ht = (t_hashtab *)ft_memalloc(sizeof(t_hashtab)))
		|| !(ht->array = (t_hashitem **)ft_memalloc(size * sizeof(t_hashitem))))
		return (NULL);
	ht->size = size;
	return (ht);
}

void		ht_del(t_hashtab *ht, char *key, void (*del)(void *, size_t))
{
	t_hashitem	*item;
	size_t		hash;

	if (ht)
	{
		hash = ht_hash(key, ht->size);
		item = ht->array[hash];
		while (item && !ft_strequ(item->key, key))
			item = item->next;
		ht_itemdel(&item, del);
	}
}

int			ht_add(t_hashtab *ht, char *key, void *data, size_t size)
{
	t_hashitem	*tmp;
	size_t		hash;

	if (!ht)
		return (1);
	hash = ht_hash(key, ht->size);
	if (!(tmp = ht->array[hash]))
		return (ht_itemadd(&ht->array[hash], key, data, size));
	else
	{
		while (tmp && !ft_strequ(tmp->key, key))
			tmp = tmp->next;
		if (!tmp)
			return (ht_itemadd(&ht->array[hash], key, data, size));
	}
	return (1);
}

void		*ht_get(t_hashtab *ht, char *key)
{
	t_hashitem	*item;
	size_t		hash;

	if (!ht)
		return (NULL);
	hash = ht_hash(key, ht->size);
	item = ht->array[hash];
	while (item && !ft_strequ(item->key, key))
		item = item->next;
	return (item ? item->data : NULL);
}

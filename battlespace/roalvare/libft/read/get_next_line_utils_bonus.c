/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:27:39 by roalvare          #+#    #+#             */
/*   Updated: 2020/06/02 09:02:28 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*free_list(t_listc *list)
{
	t_listc *next;

	while (list != NULL)
	{
		next = list->next;
		free(list);
		list = next;
	}
	return (NULL);
}

t_file	*get_file(int fd, t_file **file)
{
	t_file *new;
	t_file *cursor;

	cursor = *file;
	while (cursor != NULL)
	{
		if (cursor->fd == fd)
		{
			return (cursor);
		}
		cursor = cursor->next;
	}
	new = NULL;
	if (!(new = malloc(sizeof(t_file))))
		return (NULL);
	new->fd = fd;
	*(new->buf) = 0;
	new->crs = new->buf;
	new->next = *file;
	*file = new;
	return (new);
}

int		del_file(int fd, t_file **file)
{
	t_file	*cursor;
	t_file	*prev;

	cursor = *file;
	if (cursor->fd == fd)
		*file = cursor->next;
	else
	{
		prev = *file;
		cursor = cursor->next;
		while (cursor && cursor->fd != fd)
		{
			prev = cursor;
			cursor = cursor->next;
		}
		prev = cursor->next;
	}
	free(cursor);
	return (0);
}

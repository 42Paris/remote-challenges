/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 11:25:04 by syndraum          #+#    #+#             */
/*   Updated: 2020/06/02 09:02:30 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	static t_file	*lst_file = NULL;
	t_file			*file;
	t_listc			*lst;
	int				brk;
	int				count;

	if (line == NULL || BUFFER_SIZE <= 0)
		return (-1);
	if (!(file = get_file(fd, &lst_file)))
		return (-1);
	brk = BUFFER_SIZE;
	count = 0;
	if (!(lst = line_to_list(file, &brk, &count)))
		return (-1);
	if (!(list_to_str(lst, line, count)))
		return (-1);
	free_list(lst);
	if (brk == 0)
		return (del_file(file->fd, &lst_file));
	return (1);
}

t_listc	*line_to_list(t_file *file, int *brk, int *count)
{
	t_listc	*lst;

	lst = NULL;
	while (*(file->crs) != '\n' && *brk > 0)
	{
		if (*(file->crs) == 0)
		{
			if (-1 == (*brk = read(file->fd, file->buf, BUFFER_SIZE)))
				return (free_list(lst));
			file->buf[*brk] = 0;
			file->crs = file->buf;
		}
		if (*(file->crs) != '\n' && *(file->crs) != 0)
		{
			if (!(ft_lstnew_back(&lst, *(file->crs++))))
				return (free_list(lst));
			(*count)++;
		}
	}
	ft_lstnew_back(&lst, 0);
	if (*(file->crs) != 0)
		file->crs++;
	return (lst);
}

void	*list_to_str(t_listc *list, char **line, int len)
{
	int		i;

	i = 0;
	if (!(*line = malloc(sizeof(char) * (len + 1))))
		return (free_list(list));
	while (list->content != 0)
	{
		line[0][i++] = list->content;
		list = list->next;
	}
	line[0][i] = 0;
	return (*line);
}

int		ft_lstnew_back(t_listc **lst, char c)
{
	t_listc	*cursor;
	t_listc	*elmt;

	if (!(elmt = malloc(sizeof(t_listc))))
		return (0);
	elmt->content = c;
	elmt->next = NULL;
	if (*lst != NULL)
	{
		cursor = *lst;
		while (cursor->next != NULL)
			cursor = cursor->next;
		cursor->next = elmt;
	}
	else
		*lst = elmt;
	return (1);
}

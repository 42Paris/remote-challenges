/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:05:45 by hbaudet           #+#    #+#             */
/*   Updated: 2020/01/14 21:34:42 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_buff	*ft_lstnew_gnl(int fd)
{
	t_buff			*lst;
	int				i;

	i = 0;
	if (!(lst = malloc(sizeof(t_buff))))
		return (NULL);
	lst->filedesc = fd;
	lst->i = 0;
	lst->ret = 0;
	lst->next = NULL;
	while (i < BUFFER_SIZE)
		(lst->buff)[i++] = 0;
	return (lst);
}

int		get_next_line_part_two(char **line, t_buff *lst)
{
	int				x;

	x = lst->i;
	if (BUFFER_SIZE <= 0 || lst->filedesc == -1 || (!line))
		return (ft_error(line));
	*line = ft_strjoin_gnl("", "", 0, 0);
	while (x < lst->ret)
		if (lst->buff[x++] == '\n')
			return (ft_join_and_update(lst, line, x - 1));
	if (!(ft_join_and_update(lst, line, x)))
		return (ft_error(line));
	while (((lst->ret = read(lst->filedesc, lst->buff, BUFFER_SIZE)) > 0))
	{
		if (lst->ret == -1 || !(*line) || !line)
			return (ft_error(line));
		x = 0;
		while (x < lst->ret)
			if (lst->buff[x++] == '\n')
				return (ft_join_and_update(lst, line, x - 1));
		if (!(ft_join_and_update(lst, line, x)))
			return (ft_error(line));
	}
	return (lst->ret);
}

void	ft_lstadd_back_gnl(t_buff **alst, t_buff *new)
{
	t_buff			*lst;

	if (!alst)
		return ;
	lst = *alst;
	if (lst != NULL)
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
	else
		*alst = new;
}

int		get_next_line(int fd, char **line)
{
	static t_buff	*ptr = NULL;
	t_buff			*tmp;

	tmp = ptr;
	if (BUFFER_SIZE <= 0 || fd == -1 || (!line))
		return (ft_error(line));
	while (tmp && tmp->next)
	{
		if (tmp->filedesc == fd)
			return (get_next_line_part_two(line, tmp));
		tmp = tmp->next;
	}
	if (tmp && tmp->filedesc == fd)
		return (get_next_line_part_two(line, tmp));
	if (!(tmp = ft_lstnew_gnl(fd)))
		return (ft_error(line));
	ft_lstadd_back_gnl(&ptr, tmp);
	return (get_next_line_part_two(line, tmp));
}

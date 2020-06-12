/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:36:58 by mchardin          #+#    #+#             */
/*   Updated: 2020/04/22 22:16:26 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

int		ft_first_read(t_buf *tab, int fd, int *i)
{
	if ((*i = read(fd, tab->buf[0], B)) == -1)
		return (0);
	tab->buf[0][*i] = 0;
	tab->r = (*i == B ? 0 : 1);
	if (i != 0 && tab->r == 1 && tab->buf[0][*i - 1] == '\n')
		tab->r = 2;
	return (1);
}

int		ft_check(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		ft_copy(char **line, t_buf *tab, char **str)
{
	int		i;
	int		j;
	char	temp_buf[B + 1];

	i = 0;
	while (tab->buf[0][i] != '\n' && tab->buf[0][i])
	{
		temp_buf[i] = tab->buf[0][i];
		i++;
	}
	temp_buf[i] = 0;
	if (!(*line = ft_strjoin_gnl(*str, temp_buf)))
		return (0);
	j = 0;
	while (tab->buf[0][i] != 0 && tab->buf[0][++i])
		tab->buf[0][j++] = tab->buf[0][i];
	tab->buf[0][j] = 0;
	if (tab->buf[0][0] == 0 && tab->r == 2)
		tab->r = 0;
	*str = 0;
	return (1);
}

int		ft_str_gnl(char **str, t_buf *tab, int fd, int *i)
{
	if (!(*str = ft_strjoin_gnl(*str, tab->buf[0])))
		return (0);
	if ((*i = read(fd, tab->buf[0], B)) == -1)
	{
		ft_freez((void**)str);
		return (0);
	}
	tab->buf[0][*i] = 0;
	if (*i != B && tab->r == 0)
		tab->r = 1;
	if (i != 0 && tab->r == 1 && tab->buf[0][*i - 1] == '\n')
		tab->r = 2;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static t_buf	tab = {.buf[0][0] = -1, .r = 0};
	int				i;
	char			*str;

	str = 0;
	if (tab.buf[0][0] == -1 && (!line || B <= 0
		|| !(ft_first_read(&tab, fd, &i))))
		return (-1);
	else
		i = B;
	while (ft_check(tab.buf[0]) == -1 && i == B && !tab.r)
	{
		if (!(ft_str_gnl(&str, &tab, fd, &i)))
			return (-1);
	}
	if (!(ft_copy(line, &tab, &str)))
		return (-1);
	if (tab.r == 1 && tab.buf[0][0] == 0)
	{
		tab.buf[0][0] = -1;
		tab.r = 0;
		return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmartine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 20:42:35 by mmartine          #+#    #+#             */
/*   Updated: 2020/05/02 12:19:20 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_strclen(char *str, char c)
{
	size_t		len;

	len = 0;
	if (!str)
		return (0);
	while (*str && *str != c)
	{
		len++;
		str++;
	}
	str -= len;
	return (len);
}

static char			*ft_strsub_gnl(char *s,
	unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (s && start < ft_strclen(s, '\0'))
	{
		i = 0;
		if (!(res = ft_strnew(len)))
			return (NULL);
		while (i < len && s[start + i])
		{
			res[i] = (char)s[start + i];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}

int					get_next_line(const int fd, char **line)
{
	static char	*rest;
	char		*tmp;
	char		*buff;
	int			rd;

	if (fd < 0 || fd > 1024 || !line)
		return (-1);
	if (rest && *rest)
		tmp = ft_strdup(rest);
	else
		tmp = ft_strnew(1);
	ft_strdel(&rest);
	rd = 1;
	while (!(ft_strchr(tmp, '\n')) && rd > 0)
	{
		buff = ft_strnew(BUFF_SIZE_GNL + 1);
		rd = read(fd, buff, BUFF_SIZE_GNL);
		buff[rd] = '\0';
		tmp = ft_joinfree(tmp, buff);
	}
	*line = ft_strsub_gnl(tmp, 0, ft_strclen(tmp, '\n'));
	rest = ft_strsub_gnl(tmp, ft_strclen(tmp, '\n') + 1, ft_strlen(tmp));
	if (tmp)
		ft_strdel(&tmp);
	return ((*line && **line) ? 1 : rd);
}

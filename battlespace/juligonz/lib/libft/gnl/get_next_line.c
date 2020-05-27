/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 16:51:24 by juligonz          #+#    #+#             */
/*   Updated: 2019/11/07 16:42:15 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** return -1 of no nl, or return idx of nl
*/

static int	is_endl(char *s, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (s[i] == '\n')
			return (i);
	return (-1);
}

static int	pop_line(t_str *str, char **line)
{
	int i;
	int j;
	int	endl_idx;

	if ((endl_idx = is_endl(str->s, str->len)) != -1)
	{
		if (!(*line = malloc(endl_idx + 1)))
			return (-1);
		i = -1;
		while (++i < endl_idx)
			(*line)[i] = str->s[i];
		(*line)[i++] = '\0';
		j = 0;
		while (str->s[i] && i < str->len)
			str->s[j++] = str->s[i++];
		str->len = j;
		return (1);
	}
	return (0);
}

static int	cpy(char *d, char *s, struct s_offsets offset, int n)
{
	int i;

	i = -1;
	while (++i < n)
		d[offset.d + i] = s[offset.s + i];
	return (i);
}

static int	read_line(char **line, t_str *s, t_offsets *off, int idx)
{
	char	buffer[BUFFER_SIZE];
	int		ret;
	int		i;
	int		nl;
	int		is_line;

	if ((ret = read(s->fd, buffer, BUFFER_SIZE)) == -1)
		return (-1);
	if ((nl = is_endl(buffer, ret)) != -1 || ret != BUFFER_SIZE)
	{
		*line = malloc(idx * BUFFER_SIZE + (nl == -1 ? ret : nl) + s->len + 1);
		if (!*line)
			return (-1);
		cpy(*line, s->s, (struct s_offsets){0, 0}, s->len);
		i = cpy(*line, buffer, (struct s_offsets){(idx * BUFFER_SIZE + s->len),
					0}, (nl == -1 ? ret : nl));
		(*line)[idx * BUFFER_SIZE + s->len + i++] = '\0';
		s->len = cpy(s->s, buffer, (struct s_offsets){0, i}, ret - i);
		return (nl != -1 ? 1 : 0);
	}
	if ((is_line = read_line(line, s, off, idx + 1)) == -1)
		return (-1);
	cpy(*line, buffer,
		(struct s_offsets){idx * BUFFER_SIZE + s->old_len, 0}, ret);
	return (is_line);
}

int			get_next_line(int fd, char **line)
{
	static t_str	str;
	t_offsets		offsets;
	int				ret;

	if (fd < 0 || !line || BUFFER_SIZE < 1 || read(fd, NULL, 0) == -1)
		return (-1);
	if ((ret = pop_line(&str, line)) != 0)
		return (ret);
	str.fd = fd;
	str.old_len = str.len;
	if ((ret = read_line(line, &str, &offsets, 0)) == -1)
		return (-1);
	return (ret);
}

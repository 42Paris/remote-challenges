/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:06:09 by hben-yah          #+#    #+#             */
/*   Updated: 2019/07/19 16:55:06 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	slice(char **s1, char **s2)
{
	char	*beg;
	char	*mid;

	beg = *s2;
	mid = beg;
	while (*mid && *mid != '\n')
		++mid;
	if (*mid == '\n')
		*(mid++) = 0;
	if (!(*s1 = ft_strsub(beg, 0, mid - beg))
		|| !(mid = ft_strdup(mid)))
		return (0);
	*s2 = mid;
	free(beg);
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*files[FD_MAX + 1] = {NULL};
	char		buff[BUFF_SIZE + 1];
	int			len;

	if (fd < 0 || fd > FD_MAX
		|| (!files[fd] && !(files[fd] = ft_strnew(1))) || !line)
		return (-1);
	len = 0;
	while (ft_indexof('\n', files[fd]) < 0
			&& (len = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[len] = 0;
		if (!(files[fd] = ft_strjoinfs(files[fd], buff, FT_ARG1)))
			return (-1);
	}
	if (len < 0)
		return (-1);
	if (!*files[fd])
		return (0);
	if (!slice(line, &files[fd]))
		return (-1);
	return (**line || files[fd]);
}

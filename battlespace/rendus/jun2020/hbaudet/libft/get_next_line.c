/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:05:45 by hbaudet           #+#    #+#             */
/*   Updated: 2020/01/14 15:26:35 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static char	buff[BUFFER_SIZE >= 0 ? BUFFER_SIZE : 0];
	int			ret;
	int			i;

	i = -1;
	if (BUFFER_SIZE <= 0 || fd == -1 || (!line))
		return (ft_error(line));
	*line = ft_strjoin_gnl("", "", 0);
	while (buff[++i] && i < BUFFER_SIZE)
		if (buff[i] == '\n')
			return (ft_join_and_update(buff, i, line));
	ft_join_and_update(buff, BUFFER_SIZE, line);
	while ((ret = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		if (ret == -1 || !(*line) || (!line))
			return (ft_error(line));
		i = -1;
		while (++i < ret && buff[i])
			if (buff[i] == '\n')
				return (ft_join_and_update(buff, i, line));
		ft_join_and_update(buff, ret, line);
	}
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 10:30:07 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:19:29 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print(char *s, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		write(1, s + i, 1);
		++i;
	}
}

int		put(char *s, int len)
{
	static char	buff[PTF_BUFF_SIZE];
	static int	index = 0;
	int			left;
	int			i;

	i = len;
	if (!s || i < 0)
	{
		print(buff, index);
		i = index;
		index = 0;
		return (0);
	}
	while ((left = PTF_BUFF_SIZE - index) < i)
	{
		ft_memcpy(buff + index, s, left);
		print(buff, PTF_BUFF_SIZE);
		index = 0;
		s += left;
		i -= left;
	}
	ft_memcpy(buff + index, s, i);
	index += i;
	return (len);
}

size_t	bwrite(t_buffer *b, const char *s, size_t len)
{
	ft_memcpy(b->buff + b->len, s, len);
	b->len += len;
	return (len);
}

size_t	dblwrite(t_buffer *b, unsigned char *s, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		b->buff[b->len + i] = s[i] + '0';
		++i;
	}
	b->len += len;
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrpad.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 20:02:10 by hben-yah          #+#    #+#             */
/*   Updated: 2019/06/12 12:10:42 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstrlpad(char const *s, char c, size_t size)
{
	size_t len;

	if (s)
	{
		len = ft_strlen(s);
		while (size-- > len)
			write(1, &c, 1);
		write(1, s, len);
	}
}

void	ft_putstrrpad(char const *s, char c, size_t size)
{
	size_t len;

	if (s)
	{
		len = ft_strlen(s);
		write(1, s, len);
		while (size-- > len)
			write(1, &c, 1);
	}
}

void	ft_putstrlpad_fd(char const *s, char c, size_t size, int fd)
{
	size_t len;

	if (s)
	{
		len = ft_strlen(s);
		while (size-- > len)
			write(fd, &c, 1);
		write(fd, s, len);
	}
}

void	ft_putstrrpad_fd(char const *s, char c, size_t size, int fd)
{
	size_t len;

	if (s)
	{
		len = ft_strlen(s);
		write(fd, s, len);
		while (size-- > len)
			write(fd, &c, 1);
	}
}

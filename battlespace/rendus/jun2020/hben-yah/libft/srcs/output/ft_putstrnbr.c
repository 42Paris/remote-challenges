/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrnbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:22:23 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/12 12:18:46 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstrnbr(char *s1, long nb, char *s2)
{
	if (s1)
		write(1, s1, ft_strlen(s1));
	ft_putnbr(nb);
	if (s2)
		write(1, s2, ft_strlen(s2));
}

void	ft_putstrnbr_fd(char *s1, long nb, char *s2, int fd)
{
	if (s1)
		write(fd, s1, ft_strlen(s1));
	ft_putnbr_fd(nb, fd);
	if (s2)
		write(fd, s2, ft_strlen(s2));
}

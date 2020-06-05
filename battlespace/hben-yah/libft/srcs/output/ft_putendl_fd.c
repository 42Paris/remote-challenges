/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:23:21 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/26 11:55:29 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	if (s)
	{
		ft_putstr_fd(s, fd);
		ft_putchar_fd('\n', fd);
	}
}

void	ft_putendl2_fd(char const *s1, char const *s2, int fd)
{
	ft_putstr2_fd(s1, s2, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_putendl3_fd(char const *s1, char const *s2, char const *s3, int fd)
{
	ft_putstr3_fd(s1, s2, s3, fd);
	ft_putchar_fd('\n', fd);
}

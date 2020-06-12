/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:21:46 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/18 16:27:13 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putstr(char const *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

void	ft_putstr2(char const *s1, char const *s2)
{
	ft_putstr(s1);
	ft_putstr(s2);
}

void	ft_putstr3(char const *s1, char const *s2, char const *s3)
{
	ft_putstr(s1);
	ft_putstr(s2);
	ft_putstr(s3);
}

void	ft_putstr4(char const *s1, char const *s2,
					char const *s3, char const *s4)
{
	ft_putstr(s1);
	ft_putstr(s2);
	ft_putstr(s3);
	ft_putstr(s4);
}

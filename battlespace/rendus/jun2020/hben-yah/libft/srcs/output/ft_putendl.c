/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:22:12 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/26 11:55:24 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl(char const *s)
{
	if (s)
	{
		ft_putstr(s);
		ft_putchar('\n');
	}
}

void	ft_putendl2(char const *s1, char const *s2)
{
	ft_putstr2(s1, s2);
	ft_putchar('\n');
}

void	ft_putendl3(char const *s1, char const *s2, char const *s3)
{
	ft_putstr3(s1, s2, s3);
	ft_putchar('\n');
}

void	ft_putendl4(char const *s1, char const *s2,
					char const *s3, char const *s4)
{
	ft_putstr4(s1, s2, s3, s4);
	ft_putchar('\n');
}

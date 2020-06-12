/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:21:14 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/10 19:30:59 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wrdlen(const char *s, char c)
{
	const char *d;

	d = s;
	while (*d != c && *d)
		++d;
	return ((size_t)(d - s));
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	if (!s || !(res = ft_strtaballoc(ft_wrdcnt(s, c))))
		return (NULL);
	i = -1;
	while (*s)
	{
		if (*s != c)
		{
			if (i == -1 || *(s - 1) == c)
			{
				j = 0;
				if (!(res[++i] = ft_stralloc(ft_wrdlen(s, c))))
					return (NULL);
			}
			res[i][j++] = *s;
		}
		++s;
	}
	res[i + 1] = 0;
	return (res);
}

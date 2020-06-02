/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:21:14 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/10 19:29:14 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cut_cnt(const char *s, int (*is_separator)(int))
{
	size_t	res;

	if (!s)
		return (0);
	res = 1;
	while (is_separator(*s))
		++s;
	while (*s)
	{
		if (is_separator(*s) && !is_separator(*(s + 1)) && *(s + 1))
			++res;
		++s;
	}
	return (res);
}

static size_t	ft_wrdlen(const char *s, int (*is_end_of_word)(int))
{
	const char *d;

	d = s;
	while (!is_end_of_word(*d) && *d)
		++d;
	return ((size_t)(d - s));
}

char			**ft_split_chars(char const *s, int (*is_separator)(int))
{
	char	**res;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	if (!(res = ft_strtaballoc(ft_cut_cnt(s, is_separator))))
		return (NULL);
	i = -1;
	while (*s)
	{
		if (!is_separator(*s))
		{
			if (i == -1 || is_separator(*(s - 1)))
			{
				j = 0;
				if (!(res[++i] = ft_stralloc(ft_wrdlen(s, is_separator))))
					return (NULL);
			}
			res[i][j++] = *s;
		}
		++s;
	}
	res[i + 1] = 0;
	return (res);
}

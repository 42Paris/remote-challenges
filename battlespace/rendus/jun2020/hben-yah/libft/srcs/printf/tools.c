/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 10:29:42 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/27 10:19:24 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_length(char c, t_formatter fmt, int v)
{
	return (fmt.length & (v << ft_indexof(c, LENGTHS)));
}

int		is_flag(char c, t_formatter fmt)
{
	return ((fmt.flags & (1 << ft_indexof(c, FLAGS))) > 0);
}

char	*walk_format(char *s, int c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return (s);
		++s;
	}
	return (s);
}

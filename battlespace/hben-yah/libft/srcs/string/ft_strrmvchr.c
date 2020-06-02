/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrmvchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:11:57 by hben-yah          #+#    #+#             */
/*   Updated: 2019/04/03 15:35:20 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrmvchr(char *s, char c)
{
	char *beg;
	char *end;

	if (s && *s && c && (beg = ft_strchr(s, c)))
	{
		end = s + 1;
		while (*end)
		{
			if (*end == c)
				++end;
			else
				*(beg++) = *(end++);
		}
		*beg = *end;
	}
	return (s);
}

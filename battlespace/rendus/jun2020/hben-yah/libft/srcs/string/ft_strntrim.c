/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strntrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:06:32 by hben-yah          #+#    #+#             */
/*   Updated: 2019/04/04 17:48:29 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strntrim(char const *s, int n)
{
	char	*beg;
	char	*mid;
	char	*end;

	if (s && *s && n > 0)
	{
		beg = (char *)s;
		mid = beg;
		end = beg;
		while (*mid && mid - n != beg)
			++mid;
		if (*mid)
		{
			while (*(end + n + 1))
				++end;
			while (mid <= end)
				*(beg++) = *(mid++);
		}
		*beg = 0;
	}
	return ((char *)s);
}

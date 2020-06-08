/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrmvstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 20:17:11 by hben-yah          #+#    #+#             */
/*   Updated: 2019/06/18 11:20:58 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrmvstr(char *haystack, char *needle)
{
	char	*beg;
	char	*end;
	size_t	len;

	if (haystack && (beg = ft_strstr(haystack, needle)))
	{
		len = ft_strlen(needle);
		end = beg + len;
		while (*end)
		{
			if (ft_strnequ(end, needle, len))
				end += len;
			else
				*(beg++) = *(end++);
		}
		*beg = *end;
	}
	return (haystack);
}

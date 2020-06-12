/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:52:11 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/03 17:52:13 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len--)
	{
		i = 0;
		while (haystack[i] == needle[i] && i <= len)
			if (!needle[(i++) + 1])
				return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

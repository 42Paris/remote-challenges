/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:16:04 by roalvare          #+#    #+#             */
/*   Updated: 2019/10/22 11:11:25 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		j;

	i = 0;
	if (*needle == 0)
		return ((char*)haystack);
	while (haystack[i] && i < len)
	{
		j = 0;
		while (needle[j] != 0 && needle[j] == haystack[j + i] && i + j < len)
			j++;
		if (needle[j] == 0)
			return ((char*)&haystack[i]);
		i++;
	}
	return (0);
}

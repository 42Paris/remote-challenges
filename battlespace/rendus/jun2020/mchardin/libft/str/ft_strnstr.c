/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:20:49 by mchardin          #+#    #+#             */
/*   Updated: 2019/10/19 14:25:53 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (to_find[0] == 0)
		return ((char*)str);
	while (str[i])
	{
		while (str[i + j] == to_find[j] && len > i + j)
		{
			if (to_find[j + 1] == 0)
				return ((char*)(&str[i]));
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

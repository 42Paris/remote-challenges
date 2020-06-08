/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:08:34 by memartin          #+#    #+#             */
/*   Updated: 2020/05/02 12:22:11 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	if (s && start < ft_strlen(s))
	{
		i = 0;
		if (!(res = (char*)malloc(sizeof(char) * len + 1)))
			return (NULL);
		while (i < len && s[start + i])
		{
			res[i] = (char)s[start + i];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (ft_strdup(""));
}

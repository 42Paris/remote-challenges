/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tpierre.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 14:22:05 by tpierre           #+#    #+#             */
/*   Updated: 2020/04/06 16:57:20 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcat(char *s1, const char *s2)
{
	char *s3;

	s3 = s1;
	while (*s3)
		s3++;
	while (*s2)
		*s3++ = *s2++;
	*s3 = '\0';
	return (s1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && i + j < len)
		{
			if (!needle[j + 1])
				return ((char *)haystack + i);
			j++;
		}
		i++;
	}
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t i;

	if (!dst || !src)
		return (0);
	if (dstsize > 0)
	{
		i = 0;
		while (((char *)src)[i] && i < (dstsize - 1))
		{
			((char *)dst)[i] = ((char *)src)[i];
			i++;
		}
		((char *)dst)[i] = '\0';
	}
	return (ft_strlen(src));
}

int		ft_necklace(char *s1, char *s2)
{
	char	*str;
	int		end;

	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == NULL && s2 == NULL)
			return (1);
		else
			return (0);
	}
	end = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(s1) * 2 + 1))))
		return (0);
	ft_strlcpy(str, s1, ft_strlen(s1) + 1);
	str = ft_strcat(str, s1);
	if (ft_strnstr(str, s2, ft_strlen(str)) != NULL)
		end = 1;
	free(str);
	return (end);
}

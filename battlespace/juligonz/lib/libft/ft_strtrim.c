/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 09:28:40 by juligonz          #+#    #+#             */
/*   Updated: 2019/10/08 18:39:13 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isset(const char c, char const *set)
{
	size_t i;

	i = 0;
	while (set[i])
		if (set[i++] == c)
			return (1);
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;
	char	*res;

	start = 0;
	while (s1[start] && ft_isset(s1[start], set))
		start++;
	if (!s1[start])
		return (ft_strcpy(ft_strnew(0), ""));
	len = start - 1;
	while (s1[++len])
		end = !ft_isset(s1[len], set) ? len : end;
	if (!(res = ft_strnew(end - start + 1)))
		return (NULL);
	len = 0;
	while (start <= end)
		res[len++] = s1[start++];
	res[len] = '\0';
	return (res);
}

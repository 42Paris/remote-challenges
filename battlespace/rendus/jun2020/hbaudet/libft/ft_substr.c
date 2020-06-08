/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:35:50 by hbaudet           #+#    #+#             */
/*   Updated: 2020/01/03 11:16:33 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strndup(const char *src, size_t n)
{
	char	*ptr;
	t_uint	size;

	size = ft_strlen(src);
	if (size > n)
		size = n;
	if (!(ptr = malloc(sizeof(*ptr) * (size + 1))))
		return (NULL);
	ft_strncpy(ptr, src, size);
	ptr[size] = 0;
	return (ptr);
}

char		*ft_substr(char const *s, t_uint start, size_t len)
{
	int		i;

	i = start;
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	while (s[start])
		start++;
	if (start - i + 1 < len)
		len = start - i + 1;
	return (ft_strndup(&s[i], len));
}

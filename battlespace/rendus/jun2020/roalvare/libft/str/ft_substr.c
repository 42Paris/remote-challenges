/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 20:30:12 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/01 18:38:44 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		mem;
	int		i;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = 0;
	str = NULL;
	if (ft_strlen(s) + 1 < start)
		mem = 0;
	else if (ft_strlen(s) < start + len)
		mem = ft_strlen(s) - start;
	else
		mem = len;
	if (!(str = ft_calloc(sizeof(char), mem + 1)))
		return (NULL);
	while (mem > i)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}

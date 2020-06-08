/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 00:02:57 by juligonz          #+#    #+#             */
/*   Updated: 2019/08/14 00:03:00 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	char	*s;

	i = ft_strlen(dest);
	j = 0;
	s = (char *)src;
	while (s[j] && j < n)
		dest[i++] = s[j++];
	dest[i] = '\0';
	return (dest);
}

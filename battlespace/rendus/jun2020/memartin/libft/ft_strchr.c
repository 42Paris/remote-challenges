/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:03:51 by memartin          #+#    #+#             */
/*   Updated: 2019/10/08 13:03:52 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*tmp;

	tmp = (char*)s;
	while (*tmp)
	{
		if (*tmp == (unsigned char)c)
			return (tmp);
		tmp++;
	}
	if (*tmp == '\0' && (unsigned char)c == '\0')
		return (tmp);
	return (NULL);
}

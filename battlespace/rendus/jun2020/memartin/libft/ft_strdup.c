/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 13:07:05 by memartin          #+#    #+#             */
/*   Updated: 2020/02/19 14:42:08 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char *res;
	char *tmp;

	if (!(res = (char*)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	tmp = res;
	while (*src)
		*tmp++ = *src++;
	*tmp = '\0';
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 00:22:58 by juligonz          #+#    #+#             */
/*   Updated: 2019/10/08 09:10:11 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = -1;
	j = -1;
	while (dst[++i] && i < size)
		;
	while (src[++j] && i + j + 1 < size)
		dst[i + j] = src[j];
	if (i != size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_nosp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 11:58:02 by mchardin          #+#    #+#             */
/*   Updated: 2019/11/18 15:12:29 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		count_malloc(char *src)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (src[i])
	{
		while (src[i] == ' ')
			i++;
		if (src[i])
		{
			j++;
			i++;
		}
	}
	return (j);
}

char			*ft_strdup_no_sp(char *src)
{
	int		i;
	int		j;
	char	*dst;

	i = 0;
	j = 0;
	if (!(dst = malloc(sizeof(char) * (count_malloc(src) + 1))))
		return (0);
	while (src[i])
	{
		while (src[i] == ' ')
			i++;
		if (src[i])
		{
			dst[j] = src[i];
			j++;
			i++;
		}
	}
	dst[j] = 0;
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_cat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 17:07:13 by juligonz          #+#    #+#             */
/*   Updated: 2019/12/02 19:09:10 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup_cat(char *src, char *buf, int src_len, int buf_len)
{
	unsigned int	i;
	unsigned int	j;
	char			*ret;

	i = 0;
	if (!(ret = malloc(src_len + buf_len + 1)))
	{
		free(src);
		return (NULL);
	}
	while (src[i])
	{
		ret[i] = src[i];
		i++;
	}
	free(src);
	j = 0;
	while (buf[j])
	{
		ret[i + j] = buf[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}

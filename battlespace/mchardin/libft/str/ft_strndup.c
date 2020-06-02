/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:31:28 by mchardin          #+#    #+#             */
/*   Updated: 2020/04/22 22:43:51 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(const char *src, int len)
{
	char	*str;
	int		lg_src;
	int		i;

	lg_src = 0;
	i = 0;
	while (src[lg_src])
		lg_src++;
	if (len > lg_src)
		len = lg_src;
	if (!(str = malloc(sizeof(char) * (len + 1))))
		return (0);
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

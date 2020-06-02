/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:31:28 by mchardin          #+#    #+#             */
/*   Updated: 2020/04/22 22:37:14 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*str;
	char	*ptr;
	int		lg_src;

	lg_src = 0;
	while (src[lg_src])
		lg_src++;
	if (!(str = malloc(sizeof(char) * (lg_src + 1))))
		return (0);
	ptr = str;
	while (*src)
		*ptr++ = *src++;
	*ptr = 0;
	return (str);
}

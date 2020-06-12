/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:15:19 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/08 20:32:19 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_tabncpy(void **dst, void **src, size_t len)
{
	void **d;

	d = dst;
	while (*src && len--)
		*(d++) = (void *)*(src++);
	if (len > 0)
		while (len--)
			*(d++) = NULL;
	return (dst);
}

char	**ft_strtabncpy(char **dst, char **src, size_t len)
{
	return ((char **)ft_tabncpy((void **)dst, (void **)src, len));
}

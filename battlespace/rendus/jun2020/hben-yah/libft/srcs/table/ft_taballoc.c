/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_taballoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 18:05:57 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/24 22:31:00 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_taballoc(size_t len)
{
	void **ret;

	if (!(ret = (void **)malloc(sizeof(void *) * (len + 1))))
		return (NULL);
	ret[len] = 0;
	return (ret);
}

char	**ft_strtaballoc(size_t len)
{
	return ((char **)ft_taballoc(len));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:15:39 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/08 19:50:46 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_tabnew(size_t len)
{
	void **ret;

	if (!(ret = (void **)ft_memalloc(sizeof(void *) * (len + 1))))
		return (NULL);
	return (ret);
}

char	**ft_strtabnew(size_t len)
{
	return ((char **)ft_tabnew(len));
}

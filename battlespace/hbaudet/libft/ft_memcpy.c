/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:54:53 by hbaudet           #+#    #+#             */
/*   Updated: 2020/01/03 11:09:28 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tmp;
	const char	*bis;
	t_uint		i;

	i = 0;
	tmp = dst;
	bis = src;
	if (dst == NULL && src == NULL)
		return (dst);
	while (i < n)
	{
		tmp[i] = bis[i];
		i++;
	}
	return (dst);
}

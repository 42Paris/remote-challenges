/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:20:53 by hbaudet           #+#    #+#             */
/*   Updated: 2020/01/03 11:08:38 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char				*tmp;
	const unsigned char	*bis;
	t_uint				i;
	unsigned char		uns_c;

	i = 0;
	tmp = dst;
	bis = src;
	uns_c = (unsigned char)c;
	while (i < n)
	{
		tmp[i] = bis[i];
		if (bis[i] == uns_c)
			return (tmp + i + 1);
		i++;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:10:31 by roalvare          #+#    #+#             */
/*   Updated: 2019/10/22 11:08:11 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cursor_s1;
	unsigned char	*cursor_s2;
	size_t			i;

	cursor_s1 = (unsigned char*)s1;
	cursor_s2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (cursor_s1[i] != cursor_s2[i])
			return (cursor_s1[i] - cursor_s2[i]);
		i++;
	}
	return (0);
}

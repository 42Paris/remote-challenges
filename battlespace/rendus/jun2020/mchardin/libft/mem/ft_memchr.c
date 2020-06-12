/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:01:06 by mchardin          #+#    #+#             */
/*   Updated: 2019/10/19 14:25:53 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*temp_s;
	size_t				i;

	i = 0;
	temp_s = s;
	while (i < n)
	{
		if ((unsigned char)c == temp_s[i])
			return ((char*)&temp_s[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:01:17 by mchardin          #+#    #+#             */
/*   Updated: 2019/11/13 10:37:39 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*tmp_s1;
	const unsigned char	*tmp_s2;
	size_t				i;

	i = 0;
	tmp_s1 = s1;
	tmp_s2 = s2;
	while (i < n)
	{
		if (tmp_s1[i] != tmp_s2[i])
			return ((unsigned char)tmp_s1[i] - (unsigned char)tmp_s2[i]);
		i++;
	}
	return (0);
}

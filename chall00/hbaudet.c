/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hbaudet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 16:26:03 by hbaudet           #+#    #+#             */
/*   Updated: 2020/04/06 17:03:18 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_necklace(char *s1, char *s2)
{
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	if (!s1 && !s2)
		return (1);
	if (!s1 || !s2 || ((len = strlen(s1))
		!= (j = strlen(s2))))
		return (0);
	if (!len)
		return (1);
	while (i < len)
	{
		j = 0;
		while (s1[(i + j) % len] == s2[j])
			j++;
		if (j == len)
			return (1);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cbugnon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbugnon <cbugnon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 21:57:34 by cbugnon           #+#    #+#             */
/*   Updated: 2020/04/06 22:40:44 by cbugnon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_necklace(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;

	if (!s1 || !s2 || ft_strlen(s1) != ft_strlen(s2))
		return (0);
	if (!s1[0] && !s2[0])
		return (1);
	i = 0;
	while (i < ft_strlen(s1))
	{
		j = 0;
		while (j < ft_strlen(s2))
		{
			k = 0;
			while (s1[i] == s2[j] && k < ft_strlen(s1)
				&& s1[(i + k) % ft_strlen(s1)] == s2[(j + k) % ft_strlen(s2)])
				k++;
			if (k == ft_strlen(s1))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

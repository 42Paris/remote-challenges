/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfalkau.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfalkau <lfalkau@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 14:10:27 by lfalkau           #+#    #+#             */
/*   Updated: 2020/04/06 14:38:12 by lfalkau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

static int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned long i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static size_t	ft_strlen(const char *s)
{
	size_t len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int				ft_necklace(char *s1, char *s2)
{
	int		i;
	int		l1;
	int		l2;
	char	c;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (l1 != l2)
		return (0);
	if (l1 == 0)
		return (1);
	while (l1--)
	{
		i = 1;
		c = *s1;
		while (i < l2)
		{
			s1[i - 1] = s1[i];
			i++;
		}
		s1[i - 1] = c;
		if (ft_strcmp(s1, s2) == 0)
			return (1);
	}
	return (0);
}

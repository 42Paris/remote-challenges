/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbenjell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 14:18:40 by mbenjell          #+#    #+#             */
/*   Updated: 2020/04/06 16:33:42 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static size_t	ft_strlen(const char *s)
{
	int			i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

static int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2 && n--)
	{
		s1++;
		s2++;
	}
	if (n == 0)
		return (0);
	return (*((unsigned char*)s1) - *((unsigned char*)s2));
}

int				ft_necklace(char *s1, char *s2)
{
	int			length_1 = ft_strlen(s1);
	int			length_2 = ft_strlen(s2);
	int			n = 1;
	int			m = length_1 - 1;

	if (length_1 == 0 && length_2 == 0)
		return (1);
	else if (length_1 != length_2)
		return (0);
	else
	{
		if (length_1 == 1 && *s1 == *s2)
			return (1);
		while (m > 0)
		{
			if (ft_strncmp(s1, s2 + m, n) == 0
				&& ft_strncmp(s1 + n, s2, m) == 0)
				return (1);
			m--;
			n++;
		}
	}
  	return (0);
}

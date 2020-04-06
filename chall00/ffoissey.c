/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ffoissey.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 14:23:00 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/06 14:57:25 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#define TRUE	1
#define FALSE	0

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

static int		ft_strnequ(const char *s1, const char *s2, const size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s1[i] == s2[i])
		i++;
	return (i == n);
}

int				ft_necklace(char *s1, char *s2)
{
	size_t	len;
	size_t	i;

	if (s1 != NULL && s2 != NULL)
	{
		len = ft_strlen(s1);
		if (len == ft_strlen(s2))
		{
			if (len == 0)
				return (TRUE);
			i = 0;
			while (i < len)
			{
				if (ft_strnequ(s1, s2 + i, len - i) == TRUE
					&& ft_strnequ(s1 + len - i, s2, i) == TRUE)
					return (TRUE);
				i++;
			}
		}
	}
	return (FALSE);
}

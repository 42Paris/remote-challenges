/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcals.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:15:03 by fcals             #+#    #+#             */
/*   Updated: 2020/04/06 18:07:42 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char			*ft_strndup(const char *s, unsigned int size)
{
	char			*ptr;
	unsigned int	i;

	if (!(ptr = malloc(sizeof(char) * size + 1)))
		return (NULL);
	ptr[size] = '\0';
	i = 0;
	while (i < size)
	{
		ptr[i] = s[i];
		i++;
	}
	return (ptr);
}

static unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void			strshift(char *s, unsigned int size)
{
	char			tmp;
	unsigned int	i;

	if (size < 2)
		return ;
	tmp = s[0];
	i = 1;
	while (i < size)
	{
		s[i - 1] = s[i];
		i++;
	}
	s[size - 1] = tmp;
}

static int			ft_strequ(char *s1, char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	return (0);
}

/*
** Bruteforce
*/

int					ft_necklace(char *s1, char *s2)
{
	unsigned int	size;
	unsigned int	i;
	char			*ptr;

	if (!s1 || !s2)
		return (-1);
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	if ((size = ft_strlen(s1)) != ft_strlen(s2))
		return (0);
	if (!(ptr = ft_strndup(s1, size)))
		return (-1);
	i = 0;
	while (i < size)
	{
		strshift(ptr, size);
		if (ft_strequ(ptr, s2))
		{
			free(ptr);
			return (1);
		}
		i++;
	}
	free(ptr);
	return (0);
}

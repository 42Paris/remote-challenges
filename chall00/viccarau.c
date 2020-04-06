/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viccarau.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viccarau <viccarau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 14:11:36 by viccarau          #+#    #+#             */
/*   Updated: 2020/04/06 14:11:36 by viccarau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_strlen(char *s1)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	return (i);
}

void	ft_strcpy(void *mem, void *mem1, int size)
{
	int		i;
	char	*m;
	char	*m1;

	i = 0;
	m = (char *)mem;
	m1 = (char *)mem1;
	while (i < size)
	{
		m[i] = m1[i];
		i++;
	}
}

int		ft_strncmp(char *s1, char *s2, int size)
{
	int i;

	i = 0;
	while(i < size)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int		ft_necklace(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		a;

	if ((a = ft_strlen(s1)) == 0 && ft_strlen(s2) == 0)
		return (1);
	else if (a != ft_strlen(s2))
		return (0);
	str = (char *)malloc(((sizeof(char) * ft_strlen(s1)) * 2) + 1);
	ft_strcpy(str, s1, a);
	ft_strcpy(&str[a], s1, a);
	str[a * 2] = '\0';
	i = 0;
	while (i < a)
	{
		if (ft_strncmp(&str[i], s2, a) == 0 )
				return (1);
		i++;
	}
	str[i] = '\0';
	return (0);
}

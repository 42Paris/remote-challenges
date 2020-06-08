/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 16:22:45 by mchardin          #+#    #+#             */
/*   Updated: 2020/03/03 15:19:31 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int		ft_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			while (s[i] != c && s[i])
				i++;
			count++;
		}
	}
	return (count);
}

void	ft_free(char **strs, int count)
{
	int i;

	i = 0;
	while (i < count)
	{
		ft_freez((void **)&strs[i]);
		i++;
	}
	ft_freez((void **)&strs);
}

int		ft_split_it(char const *s, char c, char **strs, int count)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i++;
	if (!(strs[count] = malloc(sizeof(char) * (i + 1))))
	{
		ft_free(strs, count);
		return (0);
	}
	i = 0;
	while (s[i] != c && s[i])
	{
		strs[count][i] = s[i];
		i++;
	}
	strs[count][i] = 0;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		count;
	char	**strs;

	i = 0;
	count = ft_count(s, c);
	if (!(s) || !(strs = malloc(sizeof(char*) * (count + 1))))
		return (0);
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			j = ft_split_it(&s[i], c, strs, count);
			if (j == 0)
				return (0);
			i = i + j;
			count++;
		}
	}
	strs[count] = 0;
	return (strs);
}

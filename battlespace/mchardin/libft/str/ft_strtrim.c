/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:13:43 by mchardin          #+#    #+#             */
/*   Updated: 2019/10/21 19:36:52 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check_set(char const c, char const *set)
{
	int i;

	i = 0;
	while (set && set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_size(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_check_set(s1[i], set))
		i++;
	while (s1[j])
		j++;
	if (i == j)
		return (0);
	j--;
	while (ft_check_set(s1[j], set))
		j--;
	return (j - i + 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		size;
	char	*str;

	i = 0;
	j = 0;
	if (!s1)
		return (0);
	size = ft_size(s1, set);
	if (!(str = malloc(sizeof(char) * size + 1)))
		return (0);
	while (ft_check_set(s1[i], set))
		i++;
	while (j < size)
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = 0;
	return (str);
}

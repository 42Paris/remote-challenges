/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_necklace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 05:42:42 by rotrojan          #+#    #+#             */
/*   Updated: 2020/04/07 06:42:42 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		necklace_core(char *s1, char *s2)
{
	int		i1;
	int		i2;
	int		j;

	i1 = 0;
	i2 = 0;
	j = 0;
	while (s1[i1])
	{
		while (s1[i1 + j] == s2[i2])
		{
			j++;
			i2++;
			if (!s2[i2])
				return (1);
			if (!s1[i1 + j])
				j = -i1;
		}
		j = 0;
		i2 = 0;
		i1++;
	}
	return (0);
}

int		ft_necklace(char *s1, char *s2)
{
	if (!s1)
	{
		if (!s2)
			return (1);
		else
			return (0);
	}
	if (!s2)
		return (0);
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	if (!*s1 && !*s2)
		return (1);
	return (necklace_core(s1, s2));
}

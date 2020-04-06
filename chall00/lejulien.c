/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lejulien.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 21:07:49 by lejulien          #+#    #+#             */
/*   Updated: 2020/04/06 21:50:47 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int
	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static int
	ft_necklace2(char *s1, char *s2, int j)
{
	int i;
	int pointer;

	i = 0;
	pointer = 0;
	if (s2[j] == s1[i])
	{
		pointer = j;
		while (s1[i] == s2[pointer])
		{
			i++;
			pointer++;
			if (s2[pointer] == '\0')
				pointer = 0;
			if (s1[i] == '\0')
				return (1);
		}
	}
	return (0);
}

int
	ft_necklace(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ft_strlen(s1) != ft_strlen(s2))
		return (0);
	if (ft_strlen(s1) == 0)
		return (1);
	while (s2[j] != '\0')
	{
		if (ft_necklace2(s1, s2, j) == 1)
			return (1);
		j++;
	}
	return (0);
}


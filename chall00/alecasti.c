/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alecasti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecasti </var/mail/alecasti>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 16:28:14 by alecasti          #+#    #+#             */
/*   Updated: 2020/04/06 16:28:19 by alecasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (s2[i] == '\0')
		return (1);
	return (0);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_rearrange(char *str)
{
	int		i;
	char	mem;

	i = 1;
	mem = str[0];
	while (str[i] != '\0')
	{
		str[i - 1] = str[i];
		i++;
	}
	str[i - 1] = mem;
	str[i] = '\0';
}

int		ft_necklace(char *s1, char *s2)
{
	int		size;
	char	*temp;

	if (!s1 || !s2)
		return (0);
	if (ft_strcmp(s1, s2) == 1)
		return (1);
	size = ft_strlen(s1);
	if ((ft_strlen(s2) != size) || \
		!(temp = (char *)malloc(sizeof(char) * (size + 1))))
		return (0);
	while (size-- >= 0)
		temp[size] = s1[size];
	ft_rearrange(temp);
	while (ft_strcmp(s1, temp) != 1)
	{
		if (ft_strcmp(s2, temp) == 1)
		{
			free(temp);
			return (1);
		}
		ft_rearrange(temp);
	}
	free(temp);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julnolle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julien <julien@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 14:55:53 by julien            #+#    #+#             */
/*   Updated: 2020/04/06 15:35:08 by julien           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		is_necklace(char *s1, char *s2, size_t rot, size_t len1)
{
	size_t i;

	i = 0;
	while (i < len1)
	{
		if (s1[i] != s2[(i + rot) % len1])
			return (0);
		i++;
	}
	return (1);
}

int		ft_necklace(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (s1 != NULL || s2 != NULL)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		if (len1 != len2)
			return (0);
		if (len1 == 0 && len2 == 0)
			return (1);
		i = 0;
		while (i < len1)
		{
			if (is_necklace(s1, s2, i, len1))
				return (1);
			i++;
		}
	}
	else
		return (0);
	return (0);
}

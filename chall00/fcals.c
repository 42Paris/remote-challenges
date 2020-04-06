/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcals.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:15:03 by fcals             #+#    #+#             */
/*   Updated: 2020/04/06 15:42:37 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	if ((size = ft_strlen(s1)) != ft_strlen(s2))
		return(-1);
	i = 0;
	while (i < size)
	{
		strshift(s1, size);
		if (ft_strequ(s1, s2))
			return (1);
		i++;
	}
	return (0);
}

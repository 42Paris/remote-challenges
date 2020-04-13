/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcoiffie.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 14:42:33 by lcoiffie          #+#    #+#             */
/*   Updated: 2020/04/06 15:51:28 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

int	first_tests(char *s1, char *s2)
{
	int n;

	n = ft_strlen(s1);
	if (ft_strlen(s2) != n)
		return (0);
	if (n == 0)
		return (1);
	return (-1);
}

int	str_compare(char *s1, char *s2, int i, int j)
{
	while (s1[i])
	{
		if (s2[j] == '\0')
			j = 0;
		if (s1[i] != s2[j])
			break ;
		i++;
		j++;
	}
	return (i);
}

int	ft_necklace(char *s1, char *s2)
{
	int	i;
	int	j;
	int m;

	i = 0;
	j = 0;
	if ((m = first_tests(s1, s2)) >= 0)
		return (m);
	m = 0;
	while (s2[m])
	{
		if (s2[m] == s1[0])
		{
			j = m;
			i = 0;
			i = str_compare(s1, s2, i, j);
			if (i == ft_strlen(s1))
				return (1);
		}
		m++;
	}
	return (0);
}

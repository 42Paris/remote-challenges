/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wpark.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wpark <wpark@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 14:18:43 by wpark             #+#    #+#             */
/*   Updated: 2020/04/06 14:39:35 by wpark            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int check_pattern(char *s1, int idx, int len, char *s2)
{
	int i = 0;
	while (i < len)
	{
		if (s1[idx % len] != s2[i])
			return (0);
		idx++;
		i++;
	}
	return (1);
}

int ft_necklace(char *s1, char *s2)
{
	int len1 = ft_strlen(s1);
	int len2 = ft_strlen(s2);
	int i;
	
	if (!s2 || !s2 || (len1 != len2))
		return (0);
	i = 0;
	while (s1[i])
	{
		if (check_pattern(s1, i, len1, s2))
			return (1);
		i++;
	}
	if (!*s1 && !*s2)
		return (1);
	return (0);
}
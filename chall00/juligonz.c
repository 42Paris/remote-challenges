x/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juligonz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:17:15 by juligonz          #+#    #+#             */
/*   Updated: 2020/04/06 15:37:31 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

int ft_necklace(char *s1, char *s2)
{
	size_t i;
	size_t j;
	size_t k;

	if (strlen(s1) != strlen(s2))
		return (0);
	j = 0;
	while (s2[j])
	{
		if (s1[0] == s2[j])
		{
			i = 0;
			k = j;
			while (s1[i] && s1[i] == s2[k])
			{
				k = (!s2[k + 1] ? 0 : k + 1);
				i++;
			}
			if (!s1[i])
				return (1);
		}
		j++;
	}
	return (0);
}
/*
int main(int ac, char **av)
{
	(void)ac;
	printf("%d (\"%s\", \"%s\")\n", 
		   ft_necklace(av[1], av[2]),
					   av[1], av[2]);
	return (0);
}
*/

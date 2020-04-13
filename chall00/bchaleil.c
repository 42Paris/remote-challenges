/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bchaleil.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bchaleil <bchaleil@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 21:30:45 by bchaleil          #+#    #+#             */
/*   Updated: 2020/04/06 21:30:45 by bchaleil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
/* #include <stdio.h> */
#include <assert.h>

int compare_from(size_t index_s1, char *s1, char *s2)
{
	int j;
	size_t len;

	len = strlen(s2);
	j = 0;
	for (int i = 0; i < len; i++)
	{
		if (i + index_s1 > len - 1) {
			/* printf("%c %c\n", s1[j], s2[i]); */
			if (s1[j++] != s2[i])
				return (0);
		}
		else {
			/* printf("%c %c\n", s1[i + index_s1], s2[i]); */
			if (s1[i + index_s1] != s2[i])
				return (0);
		}
	}
	return (1);
}

int ft_necklace(char *s1, char *s2)
{
	/* printf("%s %s\n", s1, s2); */
	if (strlen(s1) != strlen(s2))
		return (0);
	if (strlen(s1) == 0 && strlen(s2) == 0)
		return (1);

	for (int i = 0; i < strlen(s1); i++)
	{
		if (compare_from(i, s1, s2)) {
			return (1);
		}
	}
	return (0);
}

void	main()
{
	assert(ft_necklace("nicole", "coneli") == 0);
	assert(ft_necklace("nicole", "icolen") == 1);
	assert(ft_necklace("nicole", "lenico") == 1);
	assert(ft_necklace("aabaaaaabaab", "aabaabaabaaa") == 1);
	assert(ft_necklace("abc", "cba") == 0);
	assert(ft_necklace("xxyyy", "xxxyy") == 0);
	assert(ft_necklace("xyxxz", "xxyxz") == 0);
	assert(ft_necklace("x", "x") == 1);
	assert(ft_necklace("x", "xx") == 0);
	assert(ft_necklace("x", "") == 0);
	assert(ft_necklace("", "") == 1);
}

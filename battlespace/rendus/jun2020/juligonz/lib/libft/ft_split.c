/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 18:57:27 by juligonz          #+#    #+#             */
/*   Updated: 2020/02/14 11:25:00 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		count_words(const char *str, char c)
{
	int i;
	int	count_words;

	i = -1;
	count_words = 0;
	while (str[++i])
		if (str[i] != c && (str[i + 1] == c || !str[i + 1]))
			count_words++;
	return (count_words);
}

static char		*ft_strdup_to_char(const char *src, char c)
{
	unsigned int	i;
	unsigned int	word_len;
	char			*s;

	i = 0;
	word_len = 0;
	while (src[i] && src[i] != c)
	{
		word_len++;
		i++;
	}
	if (!(s = malloc(sizeof(char) * (word_len + 1))))
		return (NULL);
	i = 0;
	while (src[i] && src[i] != c)
	{
		s[i] = src[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

char			**ft_split(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	nb_words;
	char			**res;

	if (!s)
		return (NULL);
	nb_words = count_words(s, c);
	if (!(res = malloc(sizeof(char *) * (nb_words + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (i < nb_words)
	{
		while (s[j] && s[j] == c)
			j++;
		res[i++] = ft_strdup_to_char(&s[j], c);
		while (s[j] && s[j] != c)
			j++;
	}
	res[i] = 0;
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 16:57:32 by mchardin          #+#    #+#             */
/*   Updated: 2019/10/21 19:24:58 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	unsigned int	lg_s;

	i = 0;
	lg_s = 0;
	while (s && s[lg_s])
		lg_s++;
	if (lg_s < start + 1)
	{
		if (!(s) || !(str = malloc(sizeof(char) * 1)))
			return (0);
		str[0] = 0;
		return (str);
	}
	lg_s = (len <= lg_s - start ? len : lg_s - start);
	if (!(str = malloc(sizeof(char) * (lg_s + 1))))
		return (0);
	while (i < len && s[i + start])
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = 0;
	return (str);
}

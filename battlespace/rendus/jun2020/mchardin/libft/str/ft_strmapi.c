/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:39:02 by mchardin          #+#    #+#             */
/*   Updated: 2019/10/21 19:41:17 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (0);
	i = 0;
	while (s[i])
	{
		str[i] = f ? f(i, s[i]) : s[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

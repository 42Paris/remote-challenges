/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 11:03:59 by juligonz          #+#    #+#             */
/*   Updated: 2019/10/21 11:16:03 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	i;
	char	*res;

	if (!(res = malloc(sizeof(char) * n + 1)))
		return (NULL);
	i = -1;
	while (s[++i] && n--)
		res[i] = s[i];
	res[i] = '\0';
	return (res);
}

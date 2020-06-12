/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:19:34 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/10 19:30:05 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	if (!s || !(res = ft_stralloc(ft_strlen(s))))
		return (NULL);
	i = 0;
	while (*s)
	{
		res[i] = f(i, *(s++));
		i++;
	}
	return (res);
}

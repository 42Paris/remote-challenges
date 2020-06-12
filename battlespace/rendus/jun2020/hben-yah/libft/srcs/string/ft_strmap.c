/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:19:16 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/10 19:29:58 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *r_res;
	char *res;

	if (!s || !(res = ft_stralloc(ft_strlen(s))))
		return (NULL);
	r_res = res;
	while (*s)
		*(r_res++) = f(*(s++));
	return (res);
}

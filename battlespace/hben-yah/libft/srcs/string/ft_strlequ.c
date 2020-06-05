/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 20:06:32 by hben-yah          #+#    #+#             */
/*   Updated: 2019/04/03 15:50:37 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlequ(char const *s1, char const *s2)
{
	char	*s;

	if (!s1 || !s2)
		return (s1 == s2);
	s = (char *)s1;
	while (*s1 && *s2)
		if (*(s1++) != *(s2++))
			return (0);
	return (size_t)(s1 - s);
}

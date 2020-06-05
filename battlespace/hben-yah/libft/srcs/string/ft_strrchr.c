/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:52:28 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/03 17:52:30 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *lastocc;
	char chara;

	lastocc = 0;
	chara = (char)c;
	while (*s)
	{
		if ((char)*s == chara)
			lastocc = (char *)s;
		s++;
	}
	if (lastocc)
		return (lastocc);
	return (chara == 0 ? (char *)s : NULL);
}

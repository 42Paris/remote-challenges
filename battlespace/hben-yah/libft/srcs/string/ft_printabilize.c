/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printabilize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 15:18:23 by hben-yah          #+#    #+#             */
/*   Updated: 2018/09/14 15:18:48 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_printabilize(char *str, char c)
{
	char *s;

	s = str;
	if (str)
	{
		while (*str)
		{
			if (!ft_isprint(*str))
				*str = c;
			++str;
		}
	}
	return (s);
}

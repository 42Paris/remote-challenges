/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isbase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 15:24:51 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/20 07:34:24 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isbase(char base, char *s)
{
	char dig_end;
	char up_end;
	char lc_end;

	if (base < 2 || base > 36 || !*s)
		return (-1);
	dig_end = ft_min('0' + base - 1, '9');
	up_end = ft_min('A' + base - 11, 'Z');
	lc_end = up_end + 32;
	while (*s)
	{
		if (*s < '0' || (*s > dig_end && *s < 'A')
			|| (*s > up_end && *s < 'a') || *s > lc_end)
			return (0);
		++s;
	}
	return (1);
}

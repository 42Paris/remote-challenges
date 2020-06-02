/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 19:19:27 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 22:10:56 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long		ft_atol_base(char *str, char base_len)
{
	static char	*base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	long		res;
	int			sign;
	int			i;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
	{
		sign *= -1;
		++str;
	}
	if (*str && base_len > 1)
	{
		while (*str && (i = ft_indexof(ft_toupper(*(str++)), base)) >= 0
				&& i < base_len)
			res = (res * base_len) + i;
		if (i < 0)
			return (0);
	}
	return (res * sign);
}

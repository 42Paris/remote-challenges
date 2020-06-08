/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 16:14:24 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/09 16:14:27 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_error(char *str, char *base)
{
	if (ft_strlen(str) < 1 || ft_strlen(base) < 2 || !ft_hasnodupl(base))
		return (0);
	while (*str)
	{
		if (*str != '+' && *str != '-' && ft_indexof(*str, base) == -1)
			return (0);
		++str;
	}
	while (*base)
	{
		if (*base == '+' || *base == '-' || *base < ' ' || *base > '~')
			return (0);
		++base;
	}
	return (1);
}

int			ft_atoi_base(char *str, char *base)
{
	int	res;
	int sign;
	int base_len;

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
	if (ft_check_error(str, base))
	{
		base_len = ft_strlen(base);
		while (ft_indexof(*str, base) >= 0)
			res = (res * base_len) + ft_indexof(*(str++), base);
	}
	return (res * sign);
}

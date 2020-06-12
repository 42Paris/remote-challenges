/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/13 23:33:42 by juligonz          #+#    #+#             */
/*   Updated: 2019/10/07 18:03:49 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	size_t	i;
	long	res;
	int		sign;

	i = -1;
	res = 0;
	sign = 1;
	while (ft_isspace(s[++i]))
		;
	if (s[i] == '+' || s[i] == '-')
		if (s[i++] == '-')
			sign = -1;
	while (ft_isdigit(s[i]))
		res = res * 10 + s[i++] - '0';
	return (res * sign);
}

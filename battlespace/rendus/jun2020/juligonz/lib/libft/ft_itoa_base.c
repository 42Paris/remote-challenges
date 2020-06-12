/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 17:06:19 by juligonz          #+#    #+#             */
/*   Updated: 2019/10/09 22:39:44 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_size(int n, int base)
{
	size_t res;

	if (n == 0)
		return (1);
	res = 0;
	if (n < 0)
		res++;
	while (n != 0)
	{
		n /= base;
		res++;
	}
	return (res);
}

char		*ft_itoa_base(int n, int base)
{
	int		size;
	char	*res;

	if (base < 2 || base > 16)
		return (NULL);
	size = get_size(n, base);
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (n < 0)
		res[0] = '-';
	res[size--] = '\0';
	while (size > 0)
	{
		res[size--] = (unsigned int)(n < 0 ? -n : n) % base + '0';
		res[size + 1] += (res[size + 1] > '9' ? 39 : 0);
		n /= base;
	}
	if (res[0] == '-')
		return (res);
	res[0] = (unsigned int)(n < 0 ? -n : n) % base + '0';
	res[0] += (res[0] > '9' ? 39 : 0);
	return (res);
}

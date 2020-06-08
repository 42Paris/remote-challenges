/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/14 10:16:25 by juligonz          #+#    #+#             */
/*   Updated: 2019/10/09 22:20:51 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	get_size(int n)
{
	size_t res;

	if (n == 0)
		return (1);
	res = 0;
	if (n < 0)
		res++;
	while (n != 0)
	{
		n /= 10;
		res++;
	}
	return (res);
}

char		*ft_itoa(int n)
{
	int		size;
	char	*res;

	size = get_size(n);
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	if (n < 0)
	{
		res[0] = '-';
		res[size--] = '\0';
	}
	else
		res[size--] = '\0';
	while (size > 0)
	{
		res[size--] = (unsigned int)(n < 0 ? -n : n) % 10 + '0';
		n /= 10;
	}
	if (res[0] != '-')
		res[0] = (n < 0 ? -n : n) % 10 + '0';
	return (res);
}

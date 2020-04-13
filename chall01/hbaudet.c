/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hbaudet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 14:05:09 by hbaudet           #+#    #+#             */
/*   Updated: 2020/04/13 14:23:40 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*to_hex(int i)
{
	char ret[8];
	char tmp[8];
	int	n;
	char base[] = "0123456789abcdef";
	
	n = 0;
	while (i)
	{
		ret[n] = base[i % 16];
		i /= 16;
		n++;
	}
	ret[n] = '\0';
	for (int i = 0; i < n / 2; i++)
	{
		char c;
		c = ret[i];
		ret[i] = ret[n - i - 1];
		ret[n - i - 1] = c;
	}
	tmp[0] = '#';
	tmp[1] = '\0';
	strcat(tmp, ret);
	return strdup(tmp);
}

char	*ft_rgb2hex(int r, int g, int b)
{
	long int	i;

	i = 256 * 256 * r + 256 * g + b;
	if (!i)
		return (strdup("#0"));
	return (to_hex(i));
}

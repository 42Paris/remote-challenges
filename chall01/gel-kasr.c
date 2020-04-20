/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gel-kasr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gel-kasr <gel-kasr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 14:10:14 by gel-kasr          #+#    #+#             */
/*   Updated: 2020/04/13 15:08:31 by gel-kasr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	checks(int i)
{
	return (i <= 255 && i >= 0);
}

static void	to_hex(int i, char *str)
{
	char *base;

	base = "0123456789abcdef";
	str[0] = base[i / 16];
	str[1] = base[i % 16];
}

char		*ft_rgb2hex(int r, int g, int b)
{
	char *res;

	if (!checks(r) || !checks(g) || !checks(b))
		return (NULL);
	if (!(res = (char *)malloc(8 * sizeof(char))))
		return (NULL);
	res[0] = '#';
	to_hex(r, res + 1);
	to_hex(g, res + 3);
	to_hex(b, res + 5);
	res[7] = 0;
	return (res);
}

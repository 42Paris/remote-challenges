/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenoit <abenoit@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 18:30:08 by abenoit           #+#    #+#             */
/*   Updated: 2020/04/13 20:48:42 by abenoit          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		check_input(int nb)
{
	if (nb >= 0 && nb < 256)
		return (1);
	else
		return (0);
}

char	*hex_conv(int nb, char *str)
{
	const char	hex[] = "0123456789abcdef";

	str[0] = hex[nb / 16];
	str[1] = hex[nb % 16];
	return (str);
}

char	*ft_rgb2hex(int r, int g, int b)
{
	char		*ret;

	if (!check_input(r) || !check_input(g) || !check_input(b))
		return ("Error");
	if (!(ret = malloc(8 * sizeof(char))))
		return ("Error");
	ret[0] = '#';
	hex_conv(r, &ret[1]);
	hex_conv(g, &ret[3]);
	hex_conv(b, &ret[5]);
	ret[7] = '\0';
	return (ret);
}

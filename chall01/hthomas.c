/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hthomas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 13:36:53 by hthomas           #+#    #+#             */
/*   Updated: 2020/04/14 14:12:28 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_input(int x)
{
	return (x >= 0 && x <= 255);
}

void	write_hex(char *hex, int color)
{
	const char	*base = "0123456789abcdef";

	hex[0] = base[color / 16];
	hex[1] = base[color % 16];
}

char	*ft_rgb2hex(int r, int g, int b)
{
	char	*hex;

	if (!(check_input(r) && check_input(g) && check_input(b)))
		return (NULL);
	if (!(hex = malloc(8 * sizeof(char))))
		return (NULL);
	hex[0] = '#';
	hex[7] = '\0';
	write_hex(hex + 1, r);
	write_hex(hex + 3, g);
	write_hex(hex + 5, b);
	return (hex);
}

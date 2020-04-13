/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lejulien.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lejulien <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 15:14:31 by lejulien          #+#    #+#             */
/*   Updated: 2020/04/13 16:01:56 by lejulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char
	ft_hex_base(int i, char *hextable)
{
	return (hextable[i % 16]);
}

char
	*ft_rgb2hex(int r, int g, int b)
{
	char	*res;

	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return (NULL);
	if (!(res = malloc(8 * sizeof(char))))
		return (NULL);
	res[0] = '#';
	res[1] = ft_hex_base(r, "0123456789abcdef");
	r = r / 16;
	res[2] = ft_hex_base(r, "0123456789abcdef");
	res[3] = ft_hex_base(g, "0123456789abcdef");
	g = g / 16;
	res[4] = ft_hex_base(g, "0123456789abcdef");
	res[5] = ft_hex_base(b, "0123456789abcdef");
	b = b / 16;
	res[6] = ft_hex_base(b, "0123456789abcdef");
	res[7] = '\0';
	return (res);
}

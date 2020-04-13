/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lcoiffie.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcoiffie <lcoiffie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 14:28:02 by lcoiffie          #+#    #+#             */
/*   Updated: 2020/04/13 14:45:07 by lcoiffie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_rgb2hex(int r, int g, int b)
{
	char *hex;
	char base[16] = "0123456789abcdef";

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (NULL);
	if (!(hex = (char *)malloc(sizeof(char) * 7)))
		return (NULL);
	hex[0] = '#';
	hex[1] = base[r / 16];
	hex[2] = base[r % 16];
	hex[3] = base[g / 16];
	hex[4] = base[g % 16];
	hex[5] = base[b / 16];
	hex[6] = base[b % 16];
	return (hex);
}

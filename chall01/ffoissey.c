/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ffoissey.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffoissey <ffoissey@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 14:04:27 by ffoissey          #+#    #+#             */
/*   Updated: 2020/04/13 14:21:12 by ffoissey         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_rgb2_hex(int r, int g, int b)
{
	const char	*base = "0123456789abcdef";
	char		*str;

	str = NULL;
	if ((r >= 0 && r <= 255) && (g >= 0 && g <= 255) && (b >= 0 && b <= 255))
	{
		str = (char *)malloc(sizeof(char) * (7 + 1));
		if (str != NULL)
		{
			str[0] = '#';
			str[1] = base[r / 16];
			str[2] = base[r % 16];
			str[3] = base[g / 16];
			str[4] = base[g % 16];
			str[5] = base[b / 16];
			str[6] = base[b % 16];
			str[7] = '\0';
		}
	}
	return (str);
}

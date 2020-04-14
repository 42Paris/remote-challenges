/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tpierre.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpierre <tpierre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 10:56:04 by tpierre           #+#    #+#             */
/*   Updated: 2020/04/14 12:40:00 by tpierre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_rgb2hex(int r, int g, int b)
{
	char	*str;
	char	*basehex;

	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return (NULL);
	if (!(str = (char *)malloc(sizeof(char) * 8)))
		return (NULL);
	basehex = "0123456789abcdef";
	str[0] = '#';
	str[1] = basehex[r / 16];
	str[2] = basehex[r % 16];
	str[3] = basehex[g / 16];
	str[4] = basehex[g % 16];
	str[5] = basehex[b / 16];
	str[6] = basehex[b % 16];
	str[7] = '\0';

	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgb2hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florian <fyusuf-a@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 14:53:44 by florian           #+#    #+#             */
/*   Updated: 2020/04/13 15:06:29 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char g_hexa[16] = "0123456789abcdef";

char	*ft_rgb2hex(int r, int g, int b)
{
	char	*ret;

	ret = malloc(8);
	ret[0] = '#';
	ret[1] = g_hexa[r / 16];
	ret[2] = g_hexa[r % 16];
	ret[3] = g_hexa[g / 16];
	ret[4] = g_hexa[g % 16];
	ret[5] = g_hexa[b / 16];
	ret[6] = g_hexa[b % 16];
	ret[7] = 0;
	return (ret);
}

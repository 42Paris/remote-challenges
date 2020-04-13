/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfarini <yfarini@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 14:00:15 by linux             #+#    #+#             */
/*   Updated: 2020/04/13 14:21:47 by yfarini          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_puthex(char *out, int end, int color)
{
	const char val[] = "0123456789abcdef";

	out[end] = val[color & 0xf];
	out[end - 1] = val[(color >> 4) & 0xf];
}

char	*ft_rgb2hex(int r, int g, int b)
{
	char *out;

	out = malloc(sizeof(char) * 8);
	out[7] = 0;
	out[0] = '#';
	ft_puthex(out, 6, b);
	ft_puthex(out, 4, g);
	ft_puthex(out, 2, r);
	return (out);
}

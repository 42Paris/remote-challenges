/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mbenjell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenjell <mbenjell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 14:02:40 by mbenjell          #+#    #+#             */
/*   Updated: 2020/04/13 14:52:02 by mbenjell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char					*ft_rgb2hex(int r, int g, int b)
{
	static const char	l[16] = "0123456789abcdef";
	char				*buff = malloc(8);

	buff[0] = '#';
	buff[8] = 0;
	int i = 6;
	int hex = (r << 16) + (g << 8) + b;
	while (i > 0)
	{
		buff[i--] = l[hex % 16];
		hex /= 16;
	}
	return (buff);
}

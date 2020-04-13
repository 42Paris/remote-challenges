/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcals.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcals <fcals@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 14:09:09 by fcals             #+#    #+#             */
/*   Updated: 2020/04/13 14:33:15 by fcals            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char	ctox(char x)
{
	if (x > 9)
		return (x + 'a' - 10);
	return (x + '0');
}

static void	xtoa(int *x, char *s)
{
	*(s + 1) = ctox((*x) & 15);
	*s = ctox(((*x) >> 4) & 15);
}

char		*ft_rgb2hex(int r, int g, int b)
{
	char *ptr;

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (NULL);
	if (!(ptr = malloc(sizeof(char) * 8)))
		return (NULL);
	*ptr = '#';
	*(ptr + 7) = '\0';
	xtoa(&r, ptr + 1);
	xtoa(&g, ptr + 3);
	xtoa(&b, ptr + 5);
	return (ptr);
}

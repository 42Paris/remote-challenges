/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 17:32:56 by mli               #+#    #+#             */
/*   Updated: 2020/04/14 00:07:17 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/* Explication : C'est un triple itoa fait a la main */

const char *base = "0123456789abcdef";

int		ft_good_color(int c)
{
	if (c >= 0 && c <= 255)
		return (1);
	return (0);
}

char	*ft_rgb2hex(int r, int g, int b)
{
	char *ret;

	if (!ft_good_color(r) || !ft_good_color(g) || !ft_good_color(b))
		return (NULL);
	if (!(ret = malloc(sizeof(char) * 8)))
		return (NULL);
	ret[0] = '#'; ret[7] = '\0';
	ret[2] = base[r % 16]; ret[1] = base[(r / 16) % 16];
	ret[4] = base[g % 16]; ret[3] = base[(g / 16) % 16];
	ret[6] = base[b % 16]; ret[5] = base[(b / 16) % 16];
	return (ret);
}

/*
#include <stdio.h>
#include <string.h>

int		main(void)
{
	printf("%s\n", ft_rgb2hex(252, 186, 3));
	printf("%d\n", strcmp(ft_rgb2hex(252, 186, 3), "#fcba03"));
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mli.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mli <mli@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 17:32:56 by mli               #+#    #+#             */
/*   Updated: 2020/04/13 17:47:49 by mli              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

/* Explication : C'est un triple itoa fait a la main */

char *ft_rgb2hex(int r, int g, int b)
{
	char *base = "0123456789abcdef";
	char ret[8];

	ret[0] = '#'; ret[7] = 0;
	ret[2] = base[r % 16]; ret[1] = base[(r / 16) % 16];
	ret[4] = base[g % 16]; ret[3] = base[(g / 16) % 16];
	ret[6] = base[b % 16]; ret[5] = base[(b / 16) % 16];
	return (strdup(ret));
}

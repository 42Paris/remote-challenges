/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frtalleu.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frtalleu <frtalleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 15:07:40 by frtalleu          #+#    #+#             */
/*   Updated: 2020/04/13 17:52:36 by frtalleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		check_color(int n)
{
	if (n >= 0 && n <= 255)
		return (1);
	return (0);
}

char	go_to_hex(int n, char *base)
{
	char res;

	res = base[n % 16];
	return (res);
}

char	*ft_rgb2hex(int r, int g, int b)
{
	char *res;

	if (check_color(r) == 0 || check_color(g) == 0 || check_color(b) == 0)
		return (NULL);
	if (!(res = malloc(sizeof(char) * 8)))
		return (NULL);
	res[0] = '#';
	res[7] = '\0';
	res[1] = go_to_hex(r / 16, "0123456789abcdef");
	res[2] = go_to_hex(r, "0123456789abcdef");
	res[3] = go_to_hex(g / 16, "0123456789abcdef");
	res[4] = go_to_hex(g, "0123456789abcdef");
	res[5] = go_to_hex(b / 16, "0123456789abcdef");
	res[6] = go_to_hex(b, "0123456789abcdef");
	return (res);
}

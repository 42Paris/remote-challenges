/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thninh.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thninh <thninh@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 12:16:44 by thninh            #+#    #+#             */
/*   Updated: 2020/04/14 12:16:50 by thninh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int			check_rgb(int r, int g, int b)
{
	if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
		return (1);
	return (0);
}

char		*ft_rgb2hex(int r, int g, int b)
{
	char	*hex;
	char	*base = "0123456789abcdef";

	hex = (char *)malloc(sizeof(char) * 8);
	if (!hex)
		return (NULL);
	hex[0] = '#';
	hex[7] = '\0';
	if (check_rgb(r, g, b) == 0)
		return ("the value rgb is not true\n");
	hex[1] = base[r/16];
	hex[2] = base[r%16];
	hex[3] = base[g/16];
	hex[4] = base[g%16];
	hex[5] = base[b/16];
	hex[6] = base[b%16];
	return (hex);
}

int		main(void)
{
	printf("ft_rgb2hex = %s\n", ft_rgb2hex(252, 186, 3));
	printf("ft_rgb2hex = %s\n", ft_rgb2hex(255, 0, 18));
	printf("ft_rgb2hex = %s\n", ft_rgb2hex(0, 0, 0));
	printf("ft_rgb2hex = %s\n", ft_rgb2hex(255, 255, 255));
	printf("ft_rgb2hex = %s\n", ft_rgb2hex(226, 186, 256));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotrojan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 15:24:47 by rotrojan          #+#    #+#             */
/*   Updated: 2020/04/13 16:25:34 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		check_error(int r, int g, int b)
{
	if (r < 0)
		return (0);
	if (r > 255)
		return (0);
	if (g < 0)
		return (0);
	if (g > 255)
		return (0);
	if (b < 0)
		return (0);
	if (b > 255)
		return (0);
	return (1);
}

char	*ft_rgb2hex(int r, int g, int b)
{
	char	*str;

	if (!check_error(r, g, b))
		return (NULL);
	str = malloc(sizeof(char) * 8);
	str[0] = '#';
	sprintf(str + 1, "%02x", r);
	sprintf(str + 3, "%02x", g);
	sprintf(str + 5, "%02x", b);
	str[7] = '\0';
	return (str);
}

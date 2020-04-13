/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfallet.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfallet <lfallet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 14:08:30 by lfallet           #+#    #+#             */
/*   Updated: 2020/04/13 14:42:36 by lfallet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	process_base(char *str, int color)
{
	const char	*base = "0123456789abcdef";

	str[0] = base[color / 16];
	str[1] = base[color % 16];
}

char		*ft_rgb2hex(int r, int g, int b)
{
	char	*str;
	int		color[3];
	int		i;

	str = NULL;
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return (NULL);
	str = (char *)malloc(sizeof(char) * (7 + 1));
	if (str == NULL)
		return (NULL);
	str[0] = '#';
	color[0] = r;
	color[1] = g;
	color[2] = b;
	i = 0;
	while (i < 6)
	{
		process_base(str + i + 1, color[i / 2]);
		i += 2;
	}
	str[7] = '\0';
	return (str);
}

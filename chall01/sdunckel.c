/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdunckel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdunckel <sdunckel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 14:13:39 by sdunckel          #+#    #+#             */
/*   Updated: 2020/04/13 14:43:16 by sdunckel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	add_hex(char *str, int num, int *pos)
{
	char	hex[] = "0123456789abcdef";
	int		i;

	*pos = *pos + 2;
	i = 0;
	while (i < 2)
	{
		str[*pos - i] = hex[num % 16];
		num /= 16;
		i++;
	}
}

char	*ft_rgb2hex(int r, int g, int b)
{
	char	*str;
	int		pos;

	pos = 0;
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (NULL);
	if (!(str = malloc(sizeof(char) * 8)))
		return (NULL);
	str[pos] = '#';
	add_hex(str, r, &pos);
	add_hex(str, g, &pos);
	add_hex(str, b, &pos);
	str[++pos] = '\0';
	return (str);
}

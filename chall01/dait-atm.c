/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dait-atm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dait-atm <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 18:03:41 by dait-atm          #+#    #+#             */
/*   Updated: 2020/04/13 18:09:22 by dait-atm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

static int		ft_nb_digit_custo(int n)
{
	int nbc;

	nbc = 0;
	if (n > 0)
		nbc--;
	while (n)
	{
		n /= 16;
		nbc++;
	}
	return (nbc);
}

static char		*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (len)
	{
		if (!src[i])
		{
			while (len--)
				dst[i++] = '\0';
			break ;
		}
		dst[i] = src[i];
		i++;
		len--;
	}
	return (dst);
}

static char		*i2h(int m)
{
	unsigned char	nbc;
	char			*a;

	a = malloc(sizeof(char) * 8);
	ft_strncpy(a, "#000000", 8);
	if (!m)
		return (a);
	nbc = 6;
	while (m)
	{
		if (m % 16 >= 10)
			a[nbc] = m % 16 - 10 + 'a';
		else
			a[nbc] = m % 16 + 48;
		m /= 16;
		nbc--;
	}
	return (a);
}

char			*ft_rgb2hex(int r, int g, int b)
{
	r = (0xff & r) << 16;
	r += (0xff & g) << 8;
	r += (0xff & b);
	return (i2h(r));
}

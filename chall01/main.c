/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bvalette <bvalette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 14:49:20 by bvalette          #+#    #+#             */
/*   Updated: 2020/04/13 14:59:19 by bvalette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>
#include <stdlib.h>

static size_t	ft_nb_size(long long int nb_val, size_t b_size)
{
	size_t					len;

	len = 0;
	while (nb_val > 0)
	{
		nb_val = nb_val / b_size;
		len++;
	}
	return (len);
}

static char		*ft_fill(unsigned long long n_val, int sign, int i, char *base)
{
	size_t					b_size;
	char					*ret;

	b_size = 16;
	if (!(ret = (char *)calloc(i + 1, sizeof(char))))
		return (NULL);
	i--;
	while (n_val > 0 && i >= 0)
	{
		ret[i] = base[n_val % b_size];
		n_val = n_val / b_size;
		i--;
	}
	return (ret);
}

char			*ft_itoa_base(long long int nb, char *base)
{
	int						len;
	int						sign;
	unsigned long long int	nb_val;

	sign = 1;
	if (nb < 0)
		sign = -1;
	nb_val = nb * sign;
	len = ft_nb_size(nb_val, 16) + 1;
	if (sign == -1)
		len++;
	if (nb_val == 0)
		return (strdup("0"));
	return (ft_fill(nb_val, sign, len, base));
}

char			*ft_rgb2hex(int r, int g, int b)
{
	char					*color;
	int						rgb;

	if (r == 0 && g == 0 && b == 0)
		return (strdup("0"));
	if (r >= 0 && r <= 255 && g >= 0 && g <= 255 && b >= 0 && b <= 255)
	{
		rgb = ((r << 16) | (g << 8) | b);
		color = ft_itoa_base(rgb, "0123456789abcdef");
		if (color != NULL)
			color[0] = '#';
		return (color);
	}
	else
		return (NULL);
}

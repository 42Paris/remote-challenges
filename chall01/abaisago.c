/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abaisago.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaisago <adam_bai@protonmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 21:54:31 by abaisago          #+#    #+#             */
/*   Updated: 2020/04/13 22:57:42 by abaisago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

/*
** Takes in a positive 'value' and copies it's
** base representation (2 to 36) into 'res'.
*/

void	ft_getnbr_base(size_t value, uint8_t base, char *str, size_t *index)
{
	if (value >= base)
	{
		ft_getnbr_base(value / base, base, str, index);
		ft_getnbr_base(value % base, base, str, index);
	}
	else if (value <= 9)
	{
		str[*index] = '0' + value;
		(*index)++;
	}
	else
	{
		str[*index] = 'a' + value - 10;
		(*index)++;
	}
}

/*
** Changes an integer to it's absolute value and
** outputs 1 if it has changed, 0 otherwise.
*/

int		ft_abs_is(intmax_t *n)
{
	if (*n < 0)
	{
		*n = -(*n);
		return (1);
	}
	return (0);
}

/*
** Takes an int and outputs it's allocated
** string representation in a specified base.
** Does not print negative value for bases other than 10.
*/

char	*ft_llitosa_base(int64_t value, int8_t base, char *tab)
{
	size_t		i;

	i = 0;
	if (ft_abs_is((intmax_t*)&value))
	{
		tab[0] = '-';
		++i;
	}
	ft_getnbr_base(value, base, tab, &i);
	tab[i] = '\0';
	return (tab);
}

char	*ft_rgb2hex(int r, int g, int b)
{
	char	red[3];
	char	green[3];
	char	blue[3];
	char	*hex;

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (NULL);
	if ((hex = (char*)malloc(8)) == NULL)
		return (NULL);
	ft_llitosa_base(r, 16, red);
	ft_llitosa_base(g, 16, green);
	ft_llitosa_base(b, 16, blue);
	hex[0] = '#';
	if (red[1] == '\0')
	{
		hex[1] = '0';
		hex[2] = red[0];
	}
	else
	{
		hex[1] = red[0];
		hex[2] = red[1];
	}
	if (green[1] == '\0')
	{
		hex[3] = '0';
		hex[4] = green[0];
	}
	else
	{
		hex[3] = green[0];
		hex[4] = green[1];
	}
	if (blue[1] == '\0')
	{
		hex[5] = '0';
		hex[6] = blue[0];
	}
	else
	{
		hex[5] = blue[0];
		hex[6] = blue[1];
	}
	hex[7] = '\0';
	return (hex);
}

/*
int		main(void)
{
	char	*hex;

	hex = ft_rgb2hex(252, 186, 3);
	if (strcmp(hex, "#fcba03") == 0)
		printf("libft only ez pz\n");
}
*/

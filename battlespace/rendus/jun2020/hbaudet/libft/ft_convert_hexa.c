/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:56:03 by hbaudet           #+#    #+#             */
/*   Updated: 2019/12/11 16:45:34 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_fill_ptr(long long p, unsigned int *i, char *buff, char x)
{
	long long		c;
	char			tab[17];

	c = 0;
	if (!p)
	{
		buff[0] = 48;
		return ;
	}
	if (x == 'x')
		ft_strcpy(tab, "0123456789abcdef");
	else
		ft_strcpy(tab, "0123456789ABCDEF");
	while (p)
	{
		c = p % 16;
		buff[*i] = tab[c];
		p = p / 16;
		(*i)++;
	}
	(*i)--;
}

int				ft_hex(char *buff, unsigned int *i, unsigned int p, \
	unsigned int *f)
{
	unsigned int	c;

	c = 0;
	if (f[5] && !f[1] && !p)
	{
		if (f[6] || f[4])
			c += write(1, " ", 1);
		return (c);
	}
	while (*i)
	{
		c += write(1, buff + (*i), 1);
		(*i)--;
	}
	c += write(1, buff + (*i), 1);
	return (c);
}

int				ft_write_hexa(unsigned int *f, char *buff, unsigned int *i)
{
	unsigned int	c;
	unsigned int	j;

	c = 0;
	j = 0;
	while ((f[2])-- > 14 && !f[3])
		c += write(1, " ", 1);
	c += write(1, "0x", 2);
	while ((f[6] && !f[3] && c + 12 < f[0]) || (c + 11 < f[1] && f[5]))
		c += write(1, "0", 1);
	while (j <= *i)
	{
		c += write(1, buff + (*i - j), 1);
		j++;
	}
	while ((f[2])-- > 13 && f[3])
		c += write(1, " ", 1);
	return (c);
}

unsigned int	ft_write_hexa_null(unsigned int *f)
{
	unsigned int	c;

	c = 0;
	while (((c + f[1] < f[2] && f[1] >= 1) || (c + 1 < f[2] && f[1] < 1))
	&& !f[3])
		c += write(1, " ", 1);
	while (c + 1 < f[0])
		c += write(1, "0", 1);
	while (c < f[2] && f[3])
		c += write(1, " ", 1);
	return (c);
}

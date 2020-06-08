/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 14:41:07 by hbaudet           #+#    #+#             */
/*   Updated: 2020/01/03 11:11:49 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_unsigned(t_uint nb, t_uint *f)
{
	t_uint	tmp;
	t_uint	i;
	t_uint	c;

	i = 1;
	tmp = nb;
	c = 0;
	while (tmp /= 10)
		i++;
	while (((c + f[1] < f[2] && f[1] >= i) || (c + i < f[2] && f[1] < i))
		&& !f[3])
		c += write(1, " ", 1);
	while (i++ < f[1])
		c += write(1, "0", 1);
	while (c + i <= f[0])
		c += write(1, "0", 1);
	c += ft_putnbr_printf(nb, 1, f);
	while (c < f[2] && f[3])
		c += write(1, " ", 1);
	ft_bzero(f, 7 * sizeof(int));
	return (c);
}

int	ft_conv_hex(t_uint p, t_uint *f, char x)
{
	t_uint	c;
	char	buff[11];
	t_uint	i;
	t_uint	j;

	i = 0;
	c = 0;
	j = f[5] ? f[1] : f[0];
	ft_fill_ptr(p, &i, buff, x);
	while ((f[4] && !f[3]) && ((c + i + 1 < f[2] && f[1] < i + 1)
		|| (c + f[1] < f[2] && f[1] >= i + 1)))
		c += write(1, " ", 1);
	while ((i + 1 < j && f[5]) || (f[6] && i + 1 < j))
	{
		c += write(1, "0", 1);
		j--;
	}
	c += ft_hex(buff, &i, p, f);
	while (c < f[2] && f[4] && f[3])
		c += write(1, " ", 1);
	ft_bzero(f, 7 * sizeof(int));
	return ((int)c);
}

int	ft_convert_int(int nb, t_uint *f)
{
	int		tmp;
	t_uint	i;
	t_uint	c;
	t_uint	j;

	if (nb < 0)
		return (int_neg(nb, f));
	i = 1;
	tmp = nb;
	c = 0;
	while (tmp /= 10)
		i++;
	while (!f[3] && ((f[1] >= i && c + f[1] < f[2])
		|| (f[1] < i && c + i < f[2])))
		c += write(1, " ", 1);
	j = i;
	while ((f[5] && f[1] > i++) || (f[6] && f[0] > j++))
		c += write(1, "0", 1);
	c += ft_putnbr_printf(nb, 1, f);
	while (f[3] && c < f[2])
		c += write(1, " ", 1);
	ft_bzero(f, 7 * sizeof(int));
	return (c);
}

int	ft_convert_ptr(void *ptr, t_uint *f)
{
	long long	p;
	char		buff[12];
	long long	c;
	t_uint		i;

	p = (long long)ptr;
	i = 0;
	c = 0;
	if (p)
	{
		ft_fill_ptr(p, &i, buff, 'x');
		c += ft_write_hexa(f, buff, &i);
	}
	else
	{
		while ((f[2])-- > 3 && !f[3])
			c += write(1, " ", 1);
		c += write(1, "0x0", 3);
		while ((c < f[0] && f[6]) || (f[5] && f[1] > c))
			c += write(1, "0", 1);
		while ((f[2])-- > 2 && f[3])
			c += write(1, " ", 1);
	}
	ft_bzero(f, 7 * sizeof(int));
	return ((int)c);
}

int	ft_convert_string(char *str, t_uint *f)
{
	t_uint	c;
	t_uint	size;

	c = 0;
	if (!str)
		str = ft_strdup("(null)");
	size = ft_strlen(str);
	if (size > f[1] && f[5])
		size = f[1];
	while (!f[3] && c + size < f[0] && f[6])
		c += write(1, "0", 1);
	while (c + size < f[2] && !f[3])
		c += write(1, " ", 1);
	if (str)
		c += write(1, str, size);
	else
		c += write(1, "(null)", 6);
	while (c < f[2] && f[3])
		c += write(1, " ", 1);
	ft_bzero(f, 7 * sizeof(int));
	return (c);
}

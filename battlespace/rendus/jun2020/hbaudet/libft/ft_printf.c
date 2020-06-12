/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 15:33:08 by hbaudet           #+#    #+#             */
/*   Updated: 2020/01/03 11:11:12 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags(t_uint *f, const char *av, va_list ap, int *i)
{
	if (av[*i] == '0')
		ft_arg_0(f, av, ap, i);
	else if (av[*i] == '.')
		ft_dot(f, av, ap, i);
	else if (av[*i] == '*')
		ft_arg_star(f, ap, i);
	else if (av[*i] == '-')
		ft_arg_minus(f, i);
	else if (ft_isdigit(av[*i]))
		ft_arg_num(f, av, i);
}

int		ft_convert_arg(const char *str, va_list ap, int *i)
{
	t_uint	flags[7];
	int		c;

	ft_bzero(flags, 7 * sizeof(int));
	c = 0;
	while (str[*i] == '-' || str[*i] == '.' || str[*i] == '*'
		|| ft_isdigit(str[*i]))
		ft_flags(flags, str, ap, i);
	if (str[*i] == 'c')
		c += ft_convert_char((unsigned char)va_arg(ap, int), flags);
	else if (str[*i] == 's')
		c += ft_convert_string(va_arg(ap, char *), flags);
	else if (str[*i] == 'p')
		c += ft_convert_ptr(va_arg(ap, void *), flags);
	else if (str[*i] == 'd' || str[*i] == 'i')
		c += ft_convert_int(va_arg(ap, int), flags);
	else if (str[*i] == 'u')
		c += ft_convert_unsigned(va_arg(ap, t_uint), flags);
	else if (str[*i] == 'x' || str[*i] == 'X')
		c += ft_conv_hex(va_arg(ap, t_uint), flags, str[*i]);
	else if (str[*i] == '%')
		c += ft_convert_char('%', flags);
	else
		c += write(1, &str[*i], 1);
	return (c);
}

int		ft_printf(const char *fmt, ...)
{
	int				i;
	va_list			ap;
	int				c;

	i = 0;
	c = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			c += ft_convert_arg(fmt, ap, &i);
		}
		else
			c += write(1, fmt + i, 1);
		i++;
	}
	va_end(ap);
	return (c);
}

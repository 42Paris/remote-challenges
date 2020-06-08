/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:00:48 by hbaudet           #+#    #+#             */
/*   Updated: 2020/01/13 19:04:41 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_arg_0(t_uint *f, const char *av, va_list ap, int *ind)
{
	int		tmp;

	tmp = f[3] ? 2 : 0;
	f[tmp] = 0;
	if (f[3])
		f[4] = 1;
	else
		f[6] = 1;
	(*ind)++;
	if (av[*ind] <= '9' && av[*ind] >= '0')
		while (av[*ind] <= '9' && av[*ind] >= '0')
		{
			f[tmp] = f[tmp] * 10 + av[*ind] - 48;
			(*ind)++;
		}
	else if (av[*ind] == '*')
	{
		f[tmp] = va_arg(ap, int);
		(*ind)++;
	}
}

void	ft_dot(t_uint *f, const char *av, va_list ap, int *ind)
{
	int		tmp;

	f[1] = 0;
	if (!f[4] && f[0])
	{
		f[2] = f[0];
		f[4] = 1;
	}
	f[6] = 0;
	f[5] = 1;
	(*ind)++;
	if (av[*ind] <= '9' && av[*ind] >= '0')
		while (av[*ind] <= '9' && av[*ind] >= '0')
		{
			f[1] = f[1] * 10 + av[*ind] - 48;
			(*ind)++;
		}
	else if (av[*ind] == '*')
	{
		tmp = va_arg(ap, int);
		f[1] = (tmp < 0) ? 0 : tmp;
		(*ind)++;
	}
}

void	ft_arg_minus(t_uint *f, int *ind)
{
	f[3] = 1;
	if (f[6])
	{
		f[6] = 0;
		f[4] = 1;
		f[2] = f[0];
	}
	(*ind)++;
}

void	ft_arg_star(t_uint *f, va_list ap, int *ind)
{
	long	tmp;

	tmp = va_arg(ap, int);
	if (tmp < 0)
	{
		f[2] = -tmp;
		f[3] = 1;
		f[6] = 0;
	}
	else
		f[2] = tmp;
	f[4] = 1;
	(*ind)++;
}

void	ft_arg_num(t_uint *f, const char *av, int *ind)
{
	f[2] = 0;
	f[4] = 1;
	while (av[*ind] <= '9' && av[*ind] >= '0')
	{
		f[2] = f[2] * 10 + av[*ind] - 48;
		(*ind)++;
	}
}

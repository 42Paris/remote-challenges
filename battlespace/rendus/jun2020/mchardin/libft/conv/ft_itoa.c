/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:16:17 by mchardin          #+#    #+#             */
/*   Updated: 2019/10/19 14:25:53 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void		ft_char_nbr(char *str, long n, int lg_n)
{
	str[lg_n] = 0;
	while (n > 9)
	{
		str[--lg_n] = n % 10 + '0';
		n = n / 10;
	}
	str[0] = n % 10 + '0';
}

int			ft_lg_n(int n)
{
	int	i;

	i = 0;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

char		*ft_itoa(int n)
{
	int			i;
	long		n_n;
	char		*str;
	int			sign;
	int			lg_n;

	i = 0;
	sign = 0;
	lg_n = ft_lg_n(n);
	n_n = n;
	if (n < 0)
	{
		sign = 1;
		n_n = -1 * n_n;
	}
	if (!(str = malloc(sizeof(char) * (lg_n + sign + 1))))
		return (0);
	if (sign == 1)
	{
		str[i] = '-';
		i++;
	}
	ft_char_nbr(&str[i], n_n, lg_n);
	return (str);
}

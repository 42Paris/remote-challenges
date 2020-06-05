/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:03:17 by mchardin          #+#    #+#             */
/*   Updated: 2020/04/22 22:07:37 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int				sign;
	unsigned int	nb;
	int				i;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == '\n' || str[i] == '\f' || str[i] == '\r'
			|| str[i] == ' ' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (i > 18 && str[i] > '7')
			return (sign == 1 ? -1 : 0);
		nb = 10 * nb + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

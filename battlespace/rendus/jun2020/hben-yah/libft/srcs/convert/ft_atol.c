/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 18:35:38 by hben-yah          #+#    #+#             */
/*   Updated: 2019/11/20 07:44:53 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *str)
{
	long res;
	char sign;

	res = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		++str;
	if (*str == '+')
		++str;
	else if (*str == '-')
	{
		sign *= -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
		res = (res * 10) + *(str++) - '0';
	return (res * sign);
}

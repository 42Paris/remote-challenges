/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 17:27:11 by hben-yah          #+#    #+#             */
/*   Updated: 2019/04/30 12:17:51 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		res;
	char	sign;

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

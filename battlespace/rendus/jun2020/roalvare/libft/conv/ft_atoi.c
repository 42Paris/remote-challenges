/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:22:14 by roalvare          #+#    #+#             */
/*   Updated: 2019/10/22 11:06:09 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_atoi(const char *str)
{
	int			signe;
	int			nbr;
	const char	*begin;

	signe = 1;
	nbr = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str == '-' || *str == '+')
		signe = (*(str++) == '-') ? -1 : 1;
	begin = str;
	while (*str && *str >= '0' && *str <= '9')
	{
		if (str - begin == 18 && *str - '0' > 7)
		{
			if (signe == 1)
				return (-1);
			else if (signe == -1)
				return (0);
		}
		nbr = (nbr * 10) + (*str++ - '0');
	}
	return (nbr * signe);
}

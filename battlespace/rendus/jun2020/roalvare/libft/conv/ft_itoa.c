/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:57:41 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/01 18:38:44 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_first_c(char *number, int n)
{
	*number = (n == 0) ? '0' : 0;
	*number = (n < 0) ? '-' : *number;
}

char		*ft_itoa(int n)
{
	char	*number;
	int		len;
	int		tmp;
	int		i;

	number = NULL;
	len = (n <= 0) ? 1 : 0;
	tmp = n;
	i = 0;
	while (tmp != 0)
	{
		len++;
		tmp /= 10;
	}
	tmp = n;
	if (!(number = ft_calloc(len + 1, sizeof(char))))
		return (number);
	ft_first_c(number, n);
	while (tmp != 0)
	{
		number[len - 1 - i] = ft_abs(tmp % 10) + '0';
		tmp /= 10;
		i++;
	}
	return (number);
}

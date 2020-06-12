/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:06:46 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/25 20:42:32 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen(int nbr, int base_len)
{
	size_t			len;
	unsigned int	n;

	len = 1;
	n = (unsigned int)nbr;
	if (nbr < 0)
		n *= -1;
	while (n /= base_len)
		++len;
	return (len);
}

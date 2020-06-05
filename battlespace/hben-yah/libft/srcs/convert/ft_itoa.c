/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:20:50 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/18 18:37:43 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*s;
	size_t			len;
	unsigned int	nbr;
	unsigned int	m;

	len = 1;
	nbr = (unsigned int)n;
	if (n < 0)
	{
		nbr *= -1;
		++len;
	}
	m = nbr;
	while (m /= 10)
		++len;
	if (!(s = ft_stralloc(len)))
		return (NULL);
	s[--len] = (char)((nbr % 10) + '0');
	while (nbr /= 10)
		s[--len] = (char)((nbr % 10) + '0');
	if (n < 0)
		*s = '-';
	return (s);
}

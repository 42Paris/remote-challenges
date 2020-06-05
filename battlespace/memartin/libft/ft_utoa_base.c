/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:19:58 by memartin          #+#    #+#             */
/*   Updated: 2020/02/18 15:07:15 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_ublen(unsigned long long nb, int base)
{
	size_t	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		nb /= base;
		len++;
	}
	return (len);
}

char			*ft_utoa_base(unsigned long long nb, int base)
{
	char	*ret;
	size_t	len;

	len = ft_ublen(nb, base);
	ret = ft_strnew(len);
	if (!ret)
		return (NULL);
	if (nb == 0)
		ret[0] = '0';
	while (nb > 0)
	{
		ret[--len] = nb % base > 9 ? nb % base - 10 + 'a' : nb % base + '0';
		nb /= base;
	}
	return (ret);
}

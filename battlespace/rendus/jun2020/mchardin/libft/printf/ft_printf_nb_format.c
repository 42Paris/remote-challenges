/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nb_format.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:16:17 by mchardin          #+#    #+#             */
/*   Updated: 2020/03/02 15:48:03 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		ft_conv_h(uintptr_t nb, int lg_nb, char *base_to, char *new)
{
	if (nb >= 16)
		ft_conv_h(nb / 16, lg_nb - 1, base_to, new);
	new[lg_nb - 1] = base_to[nb % 16];
}

char			*ft_convert_hexa(uintptr_t nb, char *base_to)
{
	int			lg_nb;
	uintptr_t	j;
	char		*new;

	j = nb;
	lg_nb = 0;
	while (j > 15)
	{
		j = j / 16;
		lg_nb++;
	}
	lg_nb++;
	if (!(new = malloc(sizeof(*new) * (lg_nb + 1))))
		return (0);
	ft_conv_h(nb, lg_nb, base_to, new);
	new[lg_nb] = 0;
	return (new);
}

char			*ft_itoa_un(uintptr_t n)
{
	uintptr_t	j;
	char		*str;
	int			lg_n;

	lg_n = 0;
	j = n;
	while (j > 9)
	{
		j = j / 10;
		lg_n++;
	}
	lg_n++;
	if (!(str = malloc(sizeof(char) * (lg_n + 1))))
		return (0);
	str[lg_n] = 0;
	while (n > 9)
	{
		str[--lg_n] = n % 10 + '0';
		n = n / 10;
	}
	str[0] = n % 10 + '0';
	return (str);
}

char			*ft_unsign_hexa(int nb, char chr)
{
	char			*str;
	unsigned int	un_nb;

	un_nb = (unsigned int)nb;
	if (chr == 'u' || un_nb == 0)
		str = ft_itoa_un(un_nb);
	else if (chr == 'x')
		str = ft_convert_hexa(un_nb, "0123456789abcdef");
	else
		str = ft_convert_hexa(un_nb, "0123456789ABCDEF");
	return (str);
}

char			*ft_point(uintptr_t nb)
{
	char	*str;
	char	pref[3];
	char	*new;

	pref[0] = '0';
	pref[1] = 'x';
	pref[2] = 0;
	if (nb == 0)
		str = ft_itoa_un(nb);
	else
		str = ft_convert_hexa(nb, "0123456789abcdef");
	if (!str)
		return (0);
	new = ft_strjoin(pref, str);
	ft_freez((void **)&str);
	return (new);
}

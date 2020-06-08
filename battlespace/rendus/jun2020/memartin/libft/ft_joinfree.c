/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinfree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 18:21:00 by memartin          #+#    #+#             */
/*   Updated: 2020/02/18 14:57:10 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_joinfree(char *s1, char *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	if (s1)
		ft_strdel(&s1);
	if (s2)
		ft_strdel(&s2);
	return (res);
}

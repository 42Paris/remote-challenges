/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/03 11:32:12 by hbaudet           #+#    #+#             */
/*   Updated: 2020/01/03 11:32:51 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char			*resu;
	unsigned int	i;

	i = 0;
	if (!(resu = (char *)malloc(sizeof(*resu) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		resu[i] = (*f)(i, s[i]);
		i++;
	}
	resu[i] = 0;
	return (resu);
}

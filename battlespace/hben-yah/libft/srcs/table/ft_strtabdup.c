/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:15:30 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/08 20:32:38 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strtabdup(char **tab)
{
	char	**dup;
	char	**ddup;

	if (!tab || !(dup = ft_strtaballoc(ft_strtablen(tab))))
		return (NULL);
	ddup = dup;
	while (*tab)
		if (!(*(ddup++) = ft_strdup(*(tab++))))
		{
			*(ddup) = NULL;
			ft_strtabdel(&dup);
			return (NULL);
		}
	*ddup = NULL;
	return (dup);
}

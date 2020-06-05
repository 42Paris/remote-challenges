/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:11:16 by hben-yah          #+#    #+#             */
/*   Updated: 2019/07/08 14:59:47 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tabadd(void ***tab, void *new)
{
	size_t	len;
	void	**ntab;

	if (!tab)
		return (0);
	len = *tab ? ft_tablen(*tab) : 0;
	if (!(ntab = ft_tabrealloc(*tab, len + 1)))
		return (0);
	ntab[len] = new;
	ntab[len + 1] = NULL;
	*tab = ntab;
	return (1);
}

int		ft_strtabadd(char ***tab, char *new)
{
	return (ft_tabadd((void ***)tab, (void *)new));
}

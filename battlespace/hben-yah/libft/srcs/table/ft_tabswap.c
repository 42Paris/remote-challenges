/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 16:08:03 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/29 22:06:04 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_tabswap(void ***tab1, void ***tab2)
{
	void **tmp;

	tmp = *tab1;
	*tab1 = *tab2;
	*tab2 = tmp;
}

void		ft_strtabswap(char ***tab1, char ***tab2)
{
	ft_tabswap((void ***)tab1, (void ***)tab2);
}

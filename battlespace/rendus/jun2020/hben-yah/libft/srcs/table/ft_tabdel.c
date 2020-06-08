/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 14:34:52 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/08 19:51:14 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(void ***tab)
{
	void **t;

	if (tab && *tab)
	{
		t = *tab;
		while (*t)
			ft_memdel(t++);
		free(*tab);
		*tab = NULL;
	}
}

void	ft_tabdel2(void ***tab1, void ***tab2)
{
	ft_tabdel(tab1);
	ft_tabdel(tab2);
}

void	ft_tabdel3(void ***tab1, void ***tab2, void ***tab3)
{
	ft_tabdel(tab1);
	ft_tabdel(tab2);
	ft_tabdel(tab3);
}

void	ft_tabdel4(void ***tab1, void ***tab2, void ***tab3, void ***tab4)
{
	ft_tabdel(tab1);
	ft_tabdel(tab2);
	ft_tabdel(tab3);
	ft_tabdel(tab4);
}

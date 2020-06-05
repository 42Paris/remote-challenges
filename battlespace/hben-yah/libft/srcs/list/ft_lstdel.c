/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 18:11:21 by hben-yah          #+#    #+#             */
/*   Updated: 2018/04/04 18:11:23 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*d;
	t_list	*tmp;

	if (alst && *alst)
	{
		d = *alst;
		while (d)
		{
			tmp = d;
			ft_lstdelone(&d, del);
			d = tmp->next;
		}
		*alst = NULL;
	}
}

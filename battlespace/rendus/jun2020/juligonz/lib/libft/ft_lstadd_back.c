/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 19:17:49 by juligonz          #+#    #+#             */
/*   Updated: 2019/10/11 12:48:30 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (!alst)
		return ;
	if (!*alst)
	{
		(*alst) = new;
		return ;
	}
	while ((*alst)->next)
		alst = &(*alst)->next;
	(*alst)->next = new;
}

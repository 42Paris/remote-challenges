/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 13:44:01 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/02 17:32:50 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *cursor;

	while (*lst != NULL)
	{
		cursor = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = cursor;
	}
}

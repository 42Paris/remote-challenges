/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/01 16:13:08 by user42            #+#    #+#             */
/*   Updated: 2020/05/01 17:56:12 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstprint(t_list *lst, void (*print)(void*))
{
	while (lst)
	{
		print(lst->content);
		ft_putstr_fd(" ==> ", 1);
		lst = lst->next;
	}
	ft_putstr_fd("NULL\n", 1);
}

void	print_string(void *str)
{
	ft_putstr_fd(str, 1);
}

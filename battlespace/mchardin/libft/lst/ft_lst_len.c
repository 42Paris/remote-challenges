/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:28:13 by mchardin          #+#    #+#             */
/*   Updated: 2019/12/07 15:30:12 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int			lst_len(t_list *lst)
{
	int		len;

	len = 0;
	while (lst)
	{
		len += ft_len_c((char)lst->content, 0);
		lst = lst->next;
	}
	return (len);
}

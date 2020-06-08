/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:42:15 by mchardin          #+#    #+#             */
/*   Updated: 2019/10/19 14:25:53 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*newlst;

	if (!(newlst = malloc(sizeof(t_list))))
		return (0);
	newlst->content = content;
	newlst->next = 0;
	return (newlst);
}

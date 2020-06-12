/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_node.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syndraum <syndraum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:28:53 by syndraum          #+#    #+#             */
/*   Updated: 2019/11/15 19:31:55 by syndraum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_node	*ft_newnode(char *str, int len)
{
	t_node *node;

	if (str == NULL)
		return (NULL);
	if (!(node = ft_calloc(1, sizeof(t_node))))
		return (NULL);
	node->str = str;
	node->len = len;
	return (node);
}

t_list	*create_node(char *str, int len)
{
	t_list	*lst;
	t_node	*node;

	if (str == NULL)
		return (NULL);
	if (!(node = ft_newnode(str, len)))
		return (free_content_r(str));
	if (!(lst = ft_lstnew(node)))
		return (free_node_r(node));
	return (lst);
}

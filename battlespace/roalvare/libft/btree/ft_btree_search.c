/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 17:01:42 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/03 17:03:20 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*btree_search_item(t_btree *root, void *data, int (*cmpf)(void*, void*))
{
	void	*item;

	if (root->left && (item = btree_search_item(root->left, data, cmpf)))
		return (item);
	if (!cmpf(root->item, data))
		return (root->item);
	if (root->right && (item = btree_search_item(root->right, data, cmpf)))
		return (item);
	return (NULL);
}

t_btree	*btree_search(t_btree *root, void *data, int (*cmpf)(void*, void*))
{
	t_btree	*node;

	if (root->left && (node = btree_search(root->left, data, cmpf)))
		return (node);
	if (!cmpf(root->item, data))
		return (root);
	if (root->right && (node = btree_search(root->right, data, cmpf)))
		return (node);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_apply.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 15:06:26 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/03 01:25:38 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btree.h"

void	btree_apply_prefix(t_btree *root, void (*func)(void*))
{
	func(root->item);
	if (root->left)
		btree_apply_prefix(root->left, func);
	if (root->right)
		btree_apply_prefix(root->right, func);
}

void	btree_apply_infix(t_btree *root, void (*func)(void*))
{
	if (root->left)
		btree_apply_infix(root->left, func);
	func(root->item);
	if (root->right)
		btree_apply_infix(root->right, func);
}

void	btree_apply_suffix(t_btree *root, void (*func)(void*))
{
	if (root->left)
		btree_apply_suffix(root->left, func);
	if (root->right)
		btree_apply_suffix(root->right, func);
	func(root->item);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_rotation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 00:29:54 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/05 00:30:19 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_rotate_left(t_btree **root)
{
	t_btree	*pivot;

	if ((pivot = (*root)->right))
	{
		(*root)->right = pivot->left;
		pivot->left = *root;
		*root = pivot;
	}
}

void	btree_rotate_right(t_btree **root)
{
	t_btree	*pivot;

	if ((pivot = (*root)->left))
	{
		(*root)->left = pivot->right;
		pivot->right = *root;
		*root = pivot;
	}
}

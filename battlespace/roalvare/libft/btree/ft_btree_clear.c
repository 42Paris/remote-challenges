/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_clear.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 16:45:14 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/03 16:58:04 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_clear(t_btree **root, void (*del)(void *item))
{
	if (del)
		del((*root)->item);
	if ((*root)->left)
		btree_clear(&(*root)->left, del);
	if ((*root)->right)
		btree_clear(&(*root)->right, del);
	free(*root);
	*root = NULL;
}

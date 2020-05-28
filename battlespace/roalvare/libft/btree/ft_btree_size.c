/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 16:39:03 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/03 17:02:05 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	btree_size(t_btree *root)
{
	if (!root)
		return (0);
	return (1 + btree_size(root->left) + btree_size(root->right));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 20:27:17 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/02 20:41:07 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	btree_print(t_btree *root)
{
	ft_putchar_fd('(', 1);
	if (root->left)
		btree_print(root->left);
	ft_putchar_fd(' ', 1);
	ft_putstr_fd(root->item, 1);
	ft_putchar_fd(' ', 1);
	if (root->right)
		btree_print(root->right);
	ft_putchar_fd(')', 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree_avl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 00:34:16 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/05 00:35:02 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	btree_insert_lst(t_btree **root, void *item,
	int (*cmpf)(void*, void*), t_list **lst)
{
	if (*root == NULL && (*root = btree_create_node(item)))
		(*root)->item = item;
	else if (cmpf(item, (*root)->item) < 0)
	{
		ft_lstadd_front(lst, ft_lstnew(root));
		btree_insert_lst(&(*root)->left, item, cmpf, lst);
	}
	else
	{
		ft_lstadd_front(lst, ft_lstnew(root));
		btree_insert_lst(&(*root)->right, item, cmpf, lst);
	}
}

int			get_diff_level(t_btree *node)
{
	int	diff;

	diff = btree_level_count(node->left) - btree_level_count(node->right);
	return (diff);
}

void		btree_insert_avl(t_btree **root,
	void *item, int (*cmpf)(void*, void*))
{
	t_list	*lst;
	t_btree	**node;
	int		diff_level;

	lst = NULL;
	btree_insert_lst(root, item, cmpf, &lst);
	while (lst)
	{
		node = (t_btree**)lst->content;
		diff_level = get_diff_level(*node);
		if (diff_level > 1)
			btree_rotate_right(node);
		else if (diff_level < -1)
			btree_rotate_left(node);
		free(lst);
		lst = lst->next;
	}
}

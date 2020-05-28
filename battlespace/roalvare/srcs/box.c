/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 14:57:07 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/28 11:18:52 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

t_box	*create_box()
{
	t_box	*new;
	size_t	size;

	size = sizeof(t_box);
	if (!(new = malloc(size)))
		return (NULL);
	ft_bzero(new, size);
	return (new);
}

void	add_link(t_box *parent, t_box *child, t_way dir)
{
	parent->near[dir] = child;
	child->near[(dir + 4) % 8] = parent;
}

void	add_box(t_box *parent, t_way dir)
{
	t_box	*new;

	new = create_box();
	add_link(parent, new, dir);
	if(parent->near[(dir + 2) % 8])
		add_link(new, parent->near[(dir + 2) % 8], (dir + 3) % 8);
	if(parent->near[(dir - 2) % 8])
		add_link(new, parent->near[(dir - 2) % 8], (dir - 3) % 8);
}

int		is_null(void *pointeur)
{
	if (!pointeur)
		return '.';
	else
		return '1';
}

void	print_box(t_box *node)
{
	ft_putchar_fd(is_null(node->near[UP_LEFT]), 1);
	ft_putchar_fd(is_null(node->near[UP]), 1);
	ft_putchar_fd(is_null(node->near[UP_RIGHT]), 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd(is_null(node->near[LEFT]), 1);
	ft_putchar_fd('N', 1);
	ft_putchar_fd(is_null(node->near[RIGHT]), 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd(is_null(node->near[DOWN_LEFT]), 1);
	ft_putchar_fd(is_null(node->near[DOWN]), 1);
	ft_putchar_fd(is_null(node->near[DOWN_RIGHT]), 1);
	ft_putstr_fd("\n\n", 1);
}

t_list	*ft_lstsearch(t_list *lst, void *find)
{
	while (lst)
	{
		if (lst->content == find)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	box_suffixe(t_box *root, t_list **lst)
{
	int i;

	i = -1;
	ft_lstadd_front(lst, ft_lstnew(root));
	while(++i < 8)
	{
		if(root->near[i] && !ft_lstsearch(*lst, root->near[i]))
			box_suffixe(root->near[i], lst);
	}
	print_box(root);
}
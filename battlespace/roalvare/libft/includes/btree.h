/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:41:50 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/05 00:31:19 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BTREE_H
# define BTREE_H

# include <stdlib.h>

typedef struct		s_btree
{
	struct	s_btree	*left;
	struct	s_btree	*right;
	void			*item;
}					t_btree;

t_btree				*btree_create_node(void *item);
void				btree_apply_prefix(t_btree *root, void (*func)(void*));
void				btree_apply_infix(t_btree *root, void (*func)(void*));
void				btree_apply_suffix(t_btree *root, void (*func)(void*));
void				btree_insert_data(t_btree **root, void*item, int(*cmpf)(void*,void*));
void				btree_print(t_btree *root);
void				*btree_search_item(t_btree *root, void*data, int(*cmpf)(void*,void*));
t_btree				*btree_search(t_btree *root, void *data, int(*cmpf)(void*,void*));
int					btree_level_count(t_btree *root);
void				btree_apply_level(t_btree *root,void(*applyf)(void *item));
int					btree_size(t_btree *root);
void				btree_clear(t_btree **root, void (*del)(void *item));

void				btree_rotate_left(t_btree **root);
void				btree_rotate_right(t_btree **root);

void				btree_insert_avl(t_btree **root, void *item, int (*cmpf)(void*, void*));

#endif
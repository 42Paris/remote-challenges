/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_has.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 14:11:21 by syndraum          #+#    #+#             */
/*   Updated: 2019/11/15 14:47:43 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	has_flag(t_list *l_flag, t_flag flag)
{
	while (l_flag != NULL)
	{
		if (*(unsigned char*)(l_flag->content) == flag)
			return (1);
		l_flag = l_flag->next;
	}
	return (0);
}

char	has_sign(t_list *lst)
{
	t_node	*node;

	node = (t_node*)lst->content;
	if (!ft_strncmp(node->str, "-", 1))
		return (1);
	return (0);
}

int		is_int(t_type type)
{
	const unsigned int	tab[] = {'i', 'd', 0};
	int					i;

	i = -1;
	while (tab[++i] != 0)
		if (tab[i] == type)
			return (tab[i]);
	return (0);
}

int		is_uint(t_type type)
{
	const unsigned int	tab[] = {'u', 'x', 'X', 0};
	int					i;

	i = -1;
	while (tab[++i] != 0)
		if (tab[i] == type)
			return (tab[i]);
	return (0);
}

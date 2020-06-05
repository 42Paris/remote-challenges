/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syndraum <syndraum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 13:00:20 by syndraum          #+#    #+#             */
/*   Updated: 2019/11/15 18:56:54 by syndraum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*c_char(t_conv *c)
{
	t_list	*lst;
	t_node	*node;
	char	*str;

	if (c == NULL)
		return (NULL);
	if (!(str = ft_strdup(c->content)))
		return (NULL);
	if (!(lst = s_in_lst(str, c)))
		return (NULL);
	node = (t_node*)lst->content;
	if (c->precision >= 0 && c->precision < node->len && c->type == STRING)
	{
		str[c->precision] = 0;
		node->len = ft_strlen(str);
	}
	return (lst);
}

t_list	*c_pourcent(void)
{
	char	*str;
	t_list	*lst;

	lst = NULL;
	if (!(str = ft_calloc(2, sizeof(char))))
		return (NULL);
	*str = '%';
	if (!(lst = create_node(str, 1)))
		return (NULL);
	return (lst);
}

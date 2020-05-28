/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:47:57 by syndraum          #+#    #+#             */
/*   Updated: 2019/11/15 17:17:19 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_content(void *content)
{
	if (content != NULL)
		free(content);
}

void	free_conv(void *content)
{
	t_conv *conv;

	if (content != NULL)
	{
		conv = (t_conv*)content;
		ft_lstclear(&(conv->flag), &free_content);
		free_content(conv->content);
		free(content);
	}
}

void	free_node(void *content)
{
	t_node *node;

	node = (t_node*)content;
	free_content(node->str);
	free(content);
}

void	*free_content_r(void *content)
{
	if (content != NULL)
		free(content);
	return (NULL);
}

void	*free_node_r(void *content)
{
	t_node *node;

	node = (t_node*)content;
	free_content(node->str);
	free(content);
	return (NULL);
}

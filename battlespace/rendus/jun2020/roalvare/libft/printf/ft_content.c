/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_content.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syndraum <syndraum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:27:34 by syndraum          #+#    #+#             */
/*   Updated: 2019/11/15 14:15:12 by syndraum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned char	*get_char(va_list *l_arg)
{
	unsigned char	*content;

	if (!(content = ft_calloc(sizeof(char), 2)))
		return (NULL);
	*content = (unsigned char)va_arg(*l_arg, int);
	return (content);
}

char			*get_string(va_list *l_arg)
{
	char	*content;

	if (!(content = ft_strdup(va_arg(*l_arg, char*))))
		if (!(content = ft_strdup("(null)")))
			return (NULL);
	return (content);
}

int				*get_int(va_list *l_arg)
{
	int	*content;

	if (!(content = malloc(sizeof(int))))
		return (NULL);
	*content = va_arg(*l_arg, int);
	return (content);
}

unsigned int	*get_uint(va_list *l_arg)
{
	unsigned int	*content;

	if (!(content = malloc(sizeof(unsigned int))))
		return (NULL);
	*content = va_arg(*l_arg, unsigned int);
	return (content);
}

unsigned long	*get_ulong(va_list *l_arg)
{
	unsigned long	*content;

	if (!(content = malloc(sizeof(unsigned long))))
		return (NULL);
	*content = va_arg(*l_arg, unsigned long);
	return (content);
}

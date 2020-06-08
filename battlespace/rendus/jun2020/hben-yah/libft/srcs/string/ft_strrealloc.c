/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 19:41:13 by hben-yah          #+#    #+#             */
/*   Updated: 2019/04/04 17:34:03 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrealloc(char *str, size_t len)
{
	char *new;

	if (!(new = ft_stralloc(len)))
		return (NULL);
	if (str)
	{
		ft_strlcpy(new, str, len + 1);
		free(str);
	}
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_cpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 18:26:12 by mchardin          #+#    #+#             */
/*   Updated: 2020/01/11 18:43:37 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		**ft_strs_cpy(char **strs)
{
	int			size;
	char		**new;

	size = ft_strslen(strs);
	if (!(new = malloc(sizeof(char*) * (size + 1))))
		return (0);
	new[size] = 0;
	size--;
	while (size >= 0)
	{
		new[size] = ft_strdup(strs[size]);
		size--;
	}
	return (new);
}

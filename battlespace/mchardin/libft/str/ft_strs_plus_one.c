/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_plus_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:46:41 by mchardin          #+#    #+#             */
/*   Updated: 2020/03/02 16:39:36 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char		**ft_strs_plus_one(char **strs, char *add)
{
	int			size;
	char		**new;

	size = 0;
	while (strs[size])
		size++;
	if (!(new = malloc(sizeof(char*) * (size + 2))))
	{
		ft_free_strs(&strs);
		return (0);
	}
	new[size + 1] = 0;
	new[size] = add;
	size--;
	while (size >= 0)
	{
		new[size] = strs[size];
		size--;
	}
	ft_freez((void **)&strs);
	strs = 0;
	return (new);
}

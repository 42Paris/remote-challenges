/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 11:19:24 by hben-yah          #+#    #+#             */
/*   Updated: 2019/03/15 17:57:05 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_tabrealloc(void **tab, size_t len)
{
	void **ret;

	ret = NULL;
	if (len > 0)
	{
		if (!(ret = ft_taballoc(len)))
			return (NULL);
		if (tab)
		{
			ft_tablcpy(ret, tab, len + 1);
			ret[len] = NULL;
			free(tab);
		}
		else
			*ret = NULL;
	}
	else if (tab)
		ft_tabdel(&tab);
	return (ret);
}

char	**ft_strtabrealloc(char **tab, size_t len)
{
	return ((char **)ft_tabrealloc((void **)tab, len));
}

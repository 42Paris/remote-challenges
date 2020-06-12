/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtabjoin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 16:07:57 by hben-yah          #+#    #+#             */
/*   Updated: 2019/06/18 11:21:49 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_if(char **tab1, char **tab2, char flag)
{
	if (tab1 && (flag & FT_ARG1))
		free(tab1);
	if (tab2 && (flag & FT_ARG2))
		free(tab2);
	return (NULL);
}

char		**ft_strtabjoinfs(char **tab1, char **tab2, char flag)
{
	char	**res;
	size_t	len1;

	len1 = tab1 ? ft_strtablen(tab1) : 0;
	if ((res = ft_strtaballoc(len1 + (tab2 ? ft_strtablen(tab2) : 0))))
	{
		if (tab1)
			ft_strtabcpy(res, tab1);
		if (tab2)
			ft_strtabcpy(res + len1, tab2);
	}
	free_if(tab1, tab2, flag);
	return (res);
}

char		**ft_strtabjoin(char **tab1, char **tab2)
{
	char	**res;
	size_t	len1;

	len1 = tab1 ? ft_strtablen(tab1) : 0;
	if ((res = ft_strtaballoc(len1 + (tab2 ? ft_strtablen(tab2) : 0))))
	{
		if (tab1)
			ft_strtabcpy(res, tab1);
		if (tab2)
			ft_strtabcpy(res + len1, tab2);
	}
	return (res);
}

char		**ft_strtabjoin3(char **tab1, char **tab2, char **tab3)
{
	char	**res;
	size_t	len1;
	size_t	len2;

	len1 = tab1 ? ft_strtablen(tab1) : 0;
	len2 = tab2 ? ft_strtablen(tab2) : 0;
	if ((res = ft_strtaballoc(len1 + len2 + (tab3 ? ft_strtablen(tab3) : 0))))
	{
		if (tab1)
			ft_strtabcpy(res, tab1);
		if (tab2)
			ft_strtabcpy(res + len1, tab2);
		if (tab3)
			ft_strtabcpy(res + len1 + len2, tab3);
	}
	return (res);
}

char		**ft_strtabjoin4(char **tab1, char **tab2, char **tab3, char **tab4)
{
	char	**res;
	size_t	len1;
	size_t	len2;
	size_t	len3;

	len1 = tab1 ? ft_strtablen(tab1) : 0;
	len2 = tab2 ? ft_strtablen(tab2) : 0;
	len3 = tab3 ? ft_strtablen(tab3) : 0;
	if ((res = ft_strtaballoc(len1 + len2 + len3
		+ (tab4 ? ft_strtablen(tab4) : 0))))
	{
		if (tab1)
			ft_strtabcpy(res, tab1);
		if (tab2)
			ft_strtabcpy(res + len1, tab2);
		if (tab3)
			ft_strtabcpy(res + len1 + len2, tab3);
		if (tab4)
			ft_strtabcpy(res + len1 + len2 + len3, tab4);
	}
	return (res);
}

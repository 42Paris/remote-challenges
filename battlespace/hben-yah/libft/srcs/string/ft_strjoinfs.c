/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:13:16 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/18 16:45:35 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_if(char *s1, char *s2, char *s3, char flag)
{
	if (s1 && (flag & FT_ARG1))
		free(s1);
	if (s2 && (flag & FT_ARG2))
		free(s2);
	if (s3 && (flag & FT_ARG3))
		free(s3);
	return (NULL);
}

char		*ft_strjoinfs(char *s1, char *s2, char flag)
{
	char	*res;
	size_t	len1;

	len1 = s1 ? ft_strlen(s1) : 0;
	if ((res = ft_stralloc(len1 + (s2 ? ft_strlen(s2) : 0))))
	{
		if (s1)
			ft_strcpy(res, s1);
		if (s2)
			ft_strcpy(res + len1, s2);
	}
	free_if(s1, s2, NULL, flag);
	return (res);
}

char		*ft_strjoin3fs(char *s1, char *s2, char *s3, char flag)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	len1 = s1 ? ft_strlen(s1) : 0;
	len2 = len1 + (s2 ? ft_strlen(s2) : 0);
	if ((res = ft_stralloc(len2 + (s3 ? ft_strlen(s3) : 0))))
	{
		if (s1)
			ft_strcpy(res, s1);
		if (s2)
			ft_strcpy(res + len1, s2);
		if (s3)
			ft_strcpy(res + len2, s3);
	}
	free_if(s1, s2, s3, flag);
	return (res);
}

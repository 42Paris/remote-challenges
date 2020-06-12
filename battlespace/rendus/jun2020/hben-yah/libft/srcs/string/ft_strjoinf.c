/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 11:13:16 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/10 20:30:29 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoinf(char *s1, char *s2)
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
	ft_strdel2(&s1, &s2);
	return (res);
}

char		*ft_strjoin3f(char *s1, char *s2, char *s3)
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
	ft_strdel3(&s1, &s2, &s3);
	return (res);
}

char		*ft_strjoin4f(char *s1, char *s2, char *s3, char *s4)
{
	char	*res;
	size_t	len1;
	size_t	len2;
	size_t	len3;

	len1 = ft_strlen(s1 ? s1 : "");
	len2 = len1 + ft_strlen(s2 ? s2 : "");
	len3 = len2 + ft_strlen(s3 ? s3 : "");
	if ((res = ft_stralloc(len3 + ft_strlen(s4 ? s4 : ""))))
	{
		if (s1)
			ft_strcpy(res, s1);
		if (s2)
			ft_strcpy(res + len1, s2);
		if (s3)
			ft_strcpy(res + len2, s3);
		if (s4)
			ft_strcpy(res + len3, s4);
	}
	ft_strdel4(&s1, &s2, &s3, &s4);
	return (res);
}

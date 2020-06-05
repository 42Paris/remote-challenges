/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:20:46 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/10 19:22:31 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len1;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	if (!(res = ft_stralloc(len1 + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcpy(res + len1, s2);
	return (res);
}

char	*ft_strjoin3(char const *s1, char const *s2, char const *s3)
{
	char	*res;
	size_t	len1;
	size_t	len2;

	if (!s1 || !s2 || !s3)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (!(res = ft_stralloc(len1 + len2 + ft_strlen(s3))))
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcpy(res + len1, s2);
	ft_strcpy(res + len1 + len2, s3);
	return (res);
}

char	*ft_strjoin4(char const *s1, char const *s2,
						char const *s3, char const *s4)
{
	char	*res;
	size_t	len1;
	size_t	len2;
	size_t	len3;

	if (!s1 || !s2 || !s3 || !s4)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len3 = ft_strlen(s3);
	if (!(res = ft_stralloc(len1 + len2 + len3 + ft_strlen(s4))))
		return (NULL);
	ft_strcpy(res, s1);
	ft_strcpy(res + len1, s2);
	ft_strcpy(res + len1 + len2, s3);
	ft_strcpy(res + len1 + len2 + len3, s4);
	return (res);
}

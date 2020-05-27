/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:57:22 by hbaudet           #+#    #+#             */
/*   Updated: 2020/01/03 11:16:29 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncpy_gnl(char *dest, const char *src, size_t n)
{
	t_uint i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2, t_uint n)
{
	char	*result;
	size_t	size;
	t_uint	i;
	t_uint	j;

	i = 0;
	j = 0;
	size = ft_strlen(s1) + n + 1;
	if (!(result = (char *)malloc(sizeof(*result) * size)))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	while (j < n)
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = 0;
	return (result);
}

int		ft_join_and_update(char *buff, int start, char **ptr)
{
	int			i;
	char		*tmp;

	tmp = *ptr;
	i = BUFFER_SIZE - (start + 1);
	*ptr = ft_strjoin_gnl(*ptr, buff, start);
	free(tmp);
	if (!(*ptr))
		return (ft_error(ptr));
	if (i > 0)
		ft_strncpy_gnl(buff, &buff[start + 1], i);
	else
		i = 0;
	while (i < BUFFER_SIZE)
		buff[i++] = 0;
	return (1);
}

int		ft_error(char **ptr)
{
	if (ptr && BUFFER_SIZE > 0)
		if (((*ptr) = malloc(sizeof(char) * 1)))
			(*ptr)[0] = 0;
	return (-1);
}

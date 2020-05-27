/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:57:22 by hbaudet           #+#    #+#             */
/*   Updated: 2020/01/14 21:32:56 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin_gnl(char const *s1, const char *s2, int s, int e)
{
	char			*result;
	size_t			size;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = s;
	size = ft_strlen(s1) + e - s + 1;
	if (!(result = (char *)malloc(sizeof(*result) * size)))
		return (NULL);
	while (i < ft_strlen(s1))
	{
		result[i] = s1[i];
		i++;
	}
	while (e >= 0 && j < (unsigned int)e)
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = 0;
	return (result);
}

int		ft_join_and_update(t_buff *lst, char **ptr, unsigned int x)
{
	char			*tmp;

	tmp = *ptr;
	if ((lst->buff)[x] != '\n')
	{
		*ptr = ft_strjoin_gnl(*ptr, lst->buff, lst->i, lst->ret);
		lst->i = 0;
	}
	else
	{
		*ptr = ft_strjoin_gnl(*ptr, lst->buff, lst->i, x);
		lst->i = x + 1;
	}
	if (!(*ptr))
		return (ft_error(ptr));
	free(tmp);
	return (1);
}

int		ft_error(char **ptr)
{
	if (ptr && BUFFER_SIZE > 0)
		if (((*ptr) = malloc(sizeof(char) * 1)))
			(*ptr)[0] = 0;
	return (-1);
}

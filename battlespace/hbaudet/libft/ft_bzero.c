/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:40:22 by hbaudet           #+#    #+#             */
/*   Updated: 2019/12/11 16:47:26 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char			*tmp;
	t_uint			i;

	tmp = s;
	i = 0;
	while (i < n)
	{
		tmp[i] = 0;
		i++;
	}
}

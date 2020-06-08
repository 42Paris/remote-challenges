/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:40:22 by hbaudet           #+#    #+#             */
/*   Updated: 2020/01/03 11:08:19 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_bzero_printf(void *s, size_t n, int b)
{
	char	*tmp;
	t_uint	i;

	tmp = s;
	i = 0;
	while (i < n)
	{
		tmp[i] = 0;
		i++;
	}
	return (b);
}

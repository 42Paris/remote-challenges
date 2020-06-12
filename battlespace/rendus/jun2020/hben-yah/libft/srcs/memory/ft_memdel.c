/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:17:11 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/11 15:42:10 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_memdel(void **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}

void	ft_memdel2(void **ap1, void **ap2)
{
	ft_memdel((void **)ap1);
	ft_memdel((void **)ap2);
}

void	ft_memdel3(void **ap1, void **ap2, void **ap3)
{
	ft_memdel((void **)ap1);
	ft_memdel((void **)ap2);
	ft_memdel((void **)ap3);
}

void	ft_memdel4(void **ap1, void **ap2, void **ap3, void **ap4)
{
	ft_memdel((void **)ap1);
	ft_memdel((void **)ap2);
	ft_memdel((void **)ap3);
	ft_memdel((void **)ap4);
}

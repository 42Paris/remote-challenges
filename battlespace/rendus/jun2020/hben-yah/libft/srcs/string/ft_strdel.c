/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:17:43 by hben-yah          #+#    #+#             */
/*   Updated: 2019/02/11 15:43:50 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strdel(char **as)
{
	ft_memdel((void **)as);
}

void	ft_strdel2(char **as1, char **as2)
{
	ft_memdel2((void **)as1, (void **)as2);
}

void	ft_strdel3(char **as1, char **as2, char **as3)
{
	ft_memdel3((void **)as1, (void **)as2, (void **)as3);
}

void	ft_strdel4(char **as1, char **as2, char **as3, char **as4)
{
	ft_memdel4((void **)as1, (void **)as2, (void **)as3, (void **)as4);
}

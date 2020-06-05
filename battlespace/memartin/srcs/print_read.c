/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 13:06:38 by memartin          #+#    #+#             */
/*   Updated: 2020/05/28 13:17:09 by memartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/btsp.h"

void			print_read(t_data *d)
{
	char	buff[9];

	ft_bzero(buff, 9);
	ft_putstr(d->move);
	read(0, buff, 9);
	d->res = buff[0];
}

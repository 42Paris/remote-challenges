/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 11:59:47 by hben-yah          #+#    #+#             */
/*   Updated: 2020/06/02 18:45:17 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_getc(void)
{
	static char		buff[1025];
	static short	index = 1024;
	static short	end = 0;

	if (index >= end)
	{
		index = 0;
		end = read(0, buff, 1024);
		if (end <= 0)
		{
			index = 1024;
			return (-1);
		}
		buff[end] = 0;
	}
	return (index < end ? buff[index++] : -1);
}

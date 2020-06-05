/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdittric <cdittric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 19:55:00 by cdittric          #+#    #+#             */
/*   Updated: 2020/06/02 19:55:00 by cdittric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	shoot(int x, int y, char *buf, int *bufdata)
{
	char	output[3];

	output[0] = 'a' + y;
	output[1] = '0' + x;
	output[2] = '\n';
	if (write(1, output, 3) < 0)
		return ;
	while (1)
	{
		if (bufdata[0] >= bufdata[1])
		{
			bufdata[0] = 0;
			bufdata[1] = read(0, buf, 32);
			if (bufdata[1] <= 0)
				break ;
		}
		if (buf[bufdata[0]++] == '\n')
			break ;
	}
}

int		main(void)
{
	int		i;
	int		x;
	int		y;
	char	buf[32];
	int		bufdata[2];

	bufdata[0] = 0;
	bufdata[1] = 0;
	i = 0;
	while (i < 2)
	{
		y = 0;
		while (y < 10)
		{
			x = 0;
			while (x < 10)
			{
				shoot(x, y, buf, bufdata);
				x++;
			}
			y++;
		}
		i++;
	}
	return (0);
}

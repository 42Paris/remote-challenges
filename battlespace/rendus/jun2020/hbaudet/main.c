/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaudet <hbaudet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 18:38:14 by hbaudet           #+#    #+#             */
/*   Updated: 2020/05/27 23:25:40 by hbaudet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

static void		check_shield(t_cell *shield, t_cell *cell)
{
	if (shield->i > cell->i)
		shield->i = cell->i;
	if (shield->c > cell->c)
		shield->c = cell->c;
}

static t_cell	main_loop(void)
{
	int		ret;
	t_cell	shield;
	t_cell	cell;
	char	line[9];

	cell.c = 'A' - 1;
	shield.c = 'J';
	shield.i = '9';
	while (++cell.c <= 'J')
	{
		cell.i = '0' - 1;
		while (++cell.i <= '9')
		{
			ft_printf("%c%c\n", cell.c, cell.i);
			ret = read(0, line, 8);
			line[ret > 0 ? ret : 0] = 0;
			if (!ft_strcmp(line, "BLOCKED\n"))
				check_shield(&shield, &cell);
		}
	}
	return (shield);
}

int				main(void)
{
	char	line[9];
	int		ret;
	t_cell	cell;
	t_cell	shield;

	shield = main_loop();
	cell.c = shield.c - 1;
	while (++cell.c < shield.c + 5 && cell.c <= 'J')
	{
		cell.i = shield.i - 1;
		while (++cell.i < shield.i + 5 && cell.i <= '9')
		{
			ft_printf("%c%c\n", cell.c, cell.i);
			ret = read(0, line, 8);
			line[ret > 0 ? ret : 0] = 0;
		}
	}
	return (0);
}

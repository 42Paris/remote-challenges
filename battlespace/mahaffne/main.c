/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 19:20:23 by user42            #+#    #+#             */
/*   Updated: 2020/06/02 19:20:37 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	btsp(void)
{
	char letter;
	char nb;
	char newline;

	nb = '0';
	letter = 'A';
	newline = '\n';
	while (letter <= 'J')
	{
		while (nb <= '9')
		{
			write(1, &letter, 1);
			write(1, &nb, 1);
			write(1, &newline, 1);
			nb++;
		}
		nb = '0';
		letter++;
	}
	letter = 'A';
}

int		main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	while (1)
		btsp();
	return (0);
}

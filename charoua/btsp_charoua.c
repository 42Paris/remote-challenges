/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btsp_charoua.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: charoua <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 00:44:04 by charoua           #+#    #+#             */
/*   Updated: 2020/06/02 00:46:43 by charoua          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp_charoua.h"

void	ft_write_soluce(char line, char column)
{
	write(1, &line, 1);
	write(1, &column, 1);
	write(1, "\n", 1);
}

void	ft_blocked(int i, char **blocked)
{
	while (blocked[i][0] != 'Z')
	{
		ft_putstr(blocked[i]);
		i++;
	}
}

void	ft_free(char **blocked)
{
	int i;

	i = 0;
	while (i < 26)
	{
		free(blocked[i]);
		i++;
	}
	free(blocked);
}

void	ft_solve(char **blocked, char *result, char line, char column)
{
	int i;

	i = 0;
	while (line <= 'J')
	{
		column = '0';
		while (column <= '9')
		{
			ft_write_soluce(line, column);
			read(0, result, 8);
			if (result[0] == 'B')
			{
				blocked[i][0] = line;
				blocked[i][1] = column;
				blocked[i][2] = '\n';
				blocked[i][3] = '\0';
				blocked[i + 1][0] = 'Z';
				i++;
			}
			column++;
		}
		line++;
	}
	ft_blocked(0, blocked);
	ft_free(blocked);
}

int		main(void)
{
	char	*result;
	char	**blocked;
	int		i;

	i = 0;
	if (!(result = malloc(sizeof(char) * 9)))
		return (0);
	if (!(blocked = malloc(sizeof(char*) * 26)))
		return (0);
	while (i < 26)
	{
		if (!(blocked[i] = malloc(sizeof(char) * 4)))
			return (0);
		i++;
	}
	blocked[0][0] = 'Z';
	ft_solve(blocked, result, 'A', '0');
	free(result);
	return (0);
}

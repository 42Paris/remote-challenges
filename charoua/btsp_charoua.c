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

int		ft_blocked(char ***blocked, int *i, char line, char column)
{
	(*blocked)[*i][0] = line;
	(*blocked)[*i][1] = column;
	(*blocked)[*i][2] = '\n';
	(*blocked)[*i][3] = '\0';
	(*blocked)[*i + 1][0] = 'Z';
	(*i)++;
	return (1);
}

void	ft_solve(char **blocked, char *result, char line, char column)
{
	int i;
	int block;
	int sunk;

	i = 0;
	sunk = 0;
	block = 0;
	while (line <= 'J' && sunk < 6)
	{
		column = '0';
		while (column <= '9' && sunk < 6)
		{
			result = ft_write_soluce(line, column, result);
			if (result[0] == 'B')
				block = ft_blocked(&blocked, &i, line, column);
			if (result[0] == 'S')
				sunk++;
			if (sunk == 5 && block > 0)
				sunk = 6;
			column++;
		}
		line++;
	}
	ft_write_blocked(0, blocked);
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

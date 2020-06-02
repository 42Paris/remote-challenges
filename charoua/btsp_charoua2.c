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

char	*ft_write_soluce(char line, char column, char *result)
{
	write(1, &line, 1);
	write(1, &column, 1);
	write(1, "\n", 1);
	read(0, result, 8);
	return (result);
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

void	ft_write_blocked(int i, char **blocked)
{
	while (blocked[i][0] != 'Z')
	{
		ft_putstr(blocked[i]);
		i++;
	}
	ft_free(blocked);
}

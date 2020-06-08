/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_strs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:39:44 by mchardin          #+#    #+#             */
/*   Updated: 2020/03/03 16:23:48 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_free_strs(char ***grid)
{
	int	i;

	i = 0;
	if (!grid[0])
		return ;
	while (grid[0][i])
	{
		ft_freez((void **)&grid[0][i]);
		i++;
	}
	ft_freez((void **)&grid[0]);
}

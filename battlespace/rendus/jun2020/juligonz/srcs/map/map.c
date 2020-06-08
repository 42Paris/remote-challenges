/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 17:50:36 by juligonz          #+#    #+#             */
/*   Updated: 2020/06/02 15:23:46 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "btsp.h"

t_map	create_map(int size)
{
	t_map result;

	ft_bzero(&result, sizeof(t_map));
	result.grid = malloc(size * size);
	if (result.grid == NULL)
		return (result);
	ft_memset(result.grid, '#', size * size);
	result.size = size;
	result.nb_cells = size * size;
	return (result);
}

t_map	*malloc_map(int size)
{
	t_map *result;

	if ((result = malloc(sizeof(t_map))) == NULL)
		return (NULL);
	*result = create_map(size);
	if (result->grid == NULL)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

void	destroy_map(t_map to_destroy)
{
	if (to_destroy.grid != NULL)
		free(to_destroy.grid);
}

void	free_map(t_map *to_free)
{
	destroy_map(*to_free);
	free(to_free);
}

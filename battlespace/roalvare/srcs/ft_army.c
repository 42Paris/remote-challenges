/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_army.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 18:58:27 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/28 19:05:21 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game.h>

t_army	*creat_army()
{
	t_army	*army;
	size_t size;

	size = sizeof(t_army);
	army = malloc(size);
	ft_bzero(army, size);
	return (army);
}

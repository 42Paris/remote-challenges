/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kibotrel <kibotrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 03:00:19 by kibotrel          #+#    #+#             */
/*   Updated: 2020/05/30 03:25:03 by kibotrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

void	ft_bzero(void *memory, uint32_t size)
{
	char		*string;
	uint32_t	index;

	index = 0;
	string = (char*)memory;
	while (string && size && index < size)
		string[index++] = 0;
}

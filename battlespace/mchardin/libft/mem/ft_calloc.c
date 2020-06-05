/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchardin <mchardin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:40:10 by mchardin          #+#    #+#             */
/*   Updated: 2019/11/13 10:28:18 by mchardin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char		*str;
	size_t				i;

	i = 0;
	if (!(str = malloc(count * size)))
		return (0);
	while (i < size * count)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

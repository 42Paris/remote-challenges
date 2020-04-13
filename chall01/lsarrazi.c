/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsarrazi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarrazi <lsarrazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 07:42:17 by lsarrazi          #+#    #+#             */
/*   Updated: 2020/04/13 07:57:33 by lsarrazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>

static inline
char	ft_byte2hex(int b)
{
	return (b >= 10 ? 'a' - 10 : '0') + b;
};

char	*ft_rgb2hex(int r, int g, int b)
{
	char		*ptr;
	uint64_t	buffer;

	ptr = (char*)malloc(8);
	if (ptr == 0)
		return (0);
	buffer = ft_byte2hex(b & 0xF);
	buffer = buffer << 8 | ft_byte2hex(b >> 4);
	buffer = buffer << 8 | ft_byte2hex(g & 0xF);
	buffer = buffer << 8 | ft_byte2hex(g >> 4);
	buffer = buffer << 8 | ft_byte2hex(r & 0xF);
	buffer = buffer << 8 | ft_byte2hex(r >> 4);
	buffer = buffer << 8 | '#';
	*((uint64_t*)ptr) = buffer;
	return (ptr);
}

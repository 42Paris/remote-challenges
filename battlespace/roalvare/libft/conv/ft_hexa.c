/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:26:16 by roalvare          #+#    #+#             */
/*   Updated: 2020/06/02 09:15:53 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	byte_to_hexa(char *dst, unsigned char byte)
{
	static char *hexa_base = "0123456789abcdef";

	dst[0] = hexa_base[byte >> 4];
	dst[1] = hexa_base[byte % 16];
}

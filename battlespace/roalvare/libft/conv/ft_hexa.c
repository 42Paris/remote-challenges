/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roalvare <roalvare@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/02 13:26:16 by roalvare          #+#    #+#             */
/*   Updated: 2020/05/02 13:27:29 by roalvare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	byte_to_hexa(char *dst, unsigned char byte)
{
	static char *HEXA_BASE="0123456789abcdef";

	dst[0] = HEXA_BASE[byte >> 4];
	dst[1] = HEXA_BASE[byte % 16];
}

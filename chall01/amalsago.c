/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amalsago.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 11:46:30 by amalsago          #+#    #+#             */
/*   Updated: 2020/04/13 12:37:25 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	hex[8];

char	*ft_rgb2hex(int r, int g, int b)
{
	hex[0] = '#';
	sprintf(hex + 1, "%02x", r);
	sprintf(hex + 3, "%02x", g);
	sprintf(hex + 5, "%02x", b);
	hex[7] = '\0';
	return (hex);
}

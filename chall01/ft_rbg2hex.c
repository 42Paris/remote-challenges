/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbg2hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyrlemai <cyrlemai@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 13:59:58 by cyrlemai          #+#    #+#             */
/*   Updated: 2020/04/13 14:05:14 by cyrlemai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char *ft_rgb2hex(int r, int g, int b)
{
	char *string;

	asprintf(&string, "#%02x%02x%02x", r, g, b);
	return (string);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   niragne.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niragne <niragne@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 13:58:46 by niragne           #+#    #+#             */
/*   Updated: 2020/04/13 14:04:37 by niragne          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <stdio.h>

char   *ft_rgb2hex(int r, int g, int b)
{
	char *ret;
	asprintf(&ret, "#%.2x%.2x%.2x", r, g, b);
	return (ret);
}

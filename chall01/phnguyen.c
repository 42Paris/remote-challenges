/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phnguyen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phnguyen <phnguyen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 14:02:05 by phnguyen          #+#    #+#             */
/*   Updated: 2020/04/13 14:10:55 by phnguyen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

char *ft_rgb2hex(int r, int g, int b);

char *ft_rgb2hex(int r, int g, int b)
{
	char *res;

	asprintf(&res, "#%02x%02x%02x", r, g, b);
	return (res);
}

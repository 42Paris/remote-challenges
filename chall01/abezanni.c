/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abezanni.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienbezannier <adrienbezannier@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 21:43:57 by adrienbezan       #+#    #+#             */
/*   Updated: 2020/04/13 21:59:19 by adrienbezan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void    ft_setcolor(char *color, int nbr)
{
    char *hexa;

    hexa = "0123456789abcdef";
    color[0] = hexa[nbr / 16];
    color[1] = hexa[nbr % 16];
}

char    *ft_rgb2hex(int r, int g, int b)
{
    char *color;

    if (!(color = malloc(8 * sizeof(char))))
        return (NULL);
    color[0] = '#';
    ft_setcolor(color + 1, r);
    ft_setcolor(color + 3, g);
    ft_setcolor(color + 5, b);
    color[7] = 0;
    return (color);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgbToHex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 17:38:57 by fmuller           #+#    #+#             */
/*   Updated: 2020/04/13 17:51:39 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char *ft_rgb2hex(int r, int g, int b) {
    char *str = malloc(8 * sizeof(char));
    sprintf(str, "#%02x%02x%02x", r, g, b);
    return str;
}

// int main(int argc, char const *argv[])
// {
//     printf("%d\n", strcmp(ft_rgb2hex(252, 186, 3), "#fcba03") == 0);
//     printf("%d\n", strcmp(ft_rgb2hex(25, 98, 166), "#1962a6") == 0);
//     printf("%d\n", strcmp(ft_rgb2hex(55, 227, 32), "#37e320") == 0);
//     printf("%d\n", strcmp(ft_rgb2hex(30, 255, 0), "#1eff00") == 0);
//     printf("%d\n", strcmp(ft_rgb2hex(255, 255, 255), "#ffffff") == 0);
//     printf("%d\n", strcmp(ft_rgb2hex(0, 0, 0), "#000000") == 0);
//     return 0;
// }

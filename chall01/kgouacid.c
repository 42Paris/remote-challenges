/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kgouacid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgouacid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 15:20:54 by kgouacid          #+#    #+#             */
/*   Updated: 2020/04/13 15:20:59 by kgouacid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>


int range (int n)
{
    return (n >= 0 && n <= 255);
}

void hex(char *color, int pc)
{
    char *base = "0123456789abcdef";
    color [1] = base[pc%16];
    color [0] = base[pc/16];

}


char *ft_rgb2hex(int r, int g, int b)
{
    char *color = strdup("#bimbam");
    
    if (!color || !range(r) || !range(g) || !range(b))
        return (NULL);
    hex(color + 1, r);
    hex(color + 3, g);
    hex(color + 5, b);

    return (color);
}






/*
int main()
{

printf ("%s\n",ft_rgb2hex(200, 0, 200));



// ./a.out > colors.txt


int r, g, b;
r = 0;

while (r < 256) 
{
        g = 0;
        while (g < 256) 
        {
            b = 0;
                    while (b < 256)
                    {
                            printf ("%d, %d, %d  = %s\n", r, g, b, ft_rgb2hex(r, g, b));
                            b++;
                    }
            g++;    
        }
        r++;
}
    return 0;
}

*/

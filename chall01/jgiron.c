#include <stdio.h>
#include <strings.h>
#include <string.h>
#include <stdlib.h>

char *itox(unsigned int nbr)
{
    unsigned char n;
    char *s;
    int tmp;
    int i;
    int length;
    tmp  = nbr;
    length = 1;
    while (tmp > 16)
    {
        tmp /= 16;
        length++;
    }
    if (!(s = malloc(length+ 2)))
        return(NULL);
    s[0] = '#';
    s[length+1] = 0;
    i = 1;
    while (length > 0 ){
        s[length] = "0123456789abcdef"[nbr & 0x0F];
        nbr >>= 4;
        length--;
    }
    return(s);
}

char    *ft_rgb2hex(int r, int g, int b)
{
    int hex;
    if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
        return(NULL);
    hex = (r * 256 * 256) + (g * 256) + b;
    return(itox(hex));
}
#include <stdlib.h>
#define HEX_STRING "0123456789abcdef"

static void fill_hex(int val, char *hex, int off)
{
    hex[off] = HEX_STRING[val / 16];
    hex[off + 1] = HEX_STRING[val % 16];
}

char    *ft_rgb2hex(int r, int g, int b)
{
    char *hex;

    if (!(hex = (char *)malloc(sizeof(char) * 8)))
        return (NULL);
    hex[0] = '#';
    hex[7] = 0;
    
    fill_hex(r % 256, hex, 1);
    fill_hex(g % 256, hex, 3);
    fill_hex(b % 256, hex, 5);

    return (hex);
}
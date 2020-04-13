#include <stdlib.h>

char *ft_rgb2hex(int r, int g, int b)
{
    char *result;
    char *base = "0123456789abcdef";

    if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
        return ("Error : invalid input");
    if(!(result = (char*)malloc(8 * sizeof(char))))
        return ("Error: memory allocation failed");

    result[0] = '#';
    result[1] = base[r / 16];
    result[2] = base[r % 16];
    result[3] = base[g / 16];
    result[4] = base[g % 16];
    result[5] = base[b / 16];
    result[6] = base[b % 16];
    result[7] = '\0';

    return (result);
}

#include <stdlib.h>

char *ft_rgb2hex(int r, int g, int b)
{
    const char *hex = "0123456789abcdef";
    char *ret;

    ret = malloc(sizeof(char) * 8);
    if (ret == NULL)
        return (NULL);
    ret[0] = '#';
    ret[1] = hex[r / 16];
    ret[2] = hex[r % 16];
    ret[3] = hex[g / 16];
    ret[4] = hex[g % 16];
    ret[5] = hex[b / 16];
    ret[6] = hex[b % 16];
    ret[7] = '\0';
    return (ret);
}

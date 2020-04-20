#include <stdio.h>
#include <stdlib.h>

char *ft_rgb2hex(int r, int g, int b)
{
    char *out;

    out = malloc(sizeof(char) * 8);
    if (out) {
        sprintf(out, "#%02x%02x%02x", r, g, b);
    }

    return out;
}
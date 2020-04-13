#include <stdio.h>

/*
** Needed to compile without warning, see
** https://github.com/nicowilliams/inplace/issues/6
** for details.
*/

#define _GNU_SOURCE 1

int     asprintf(char **str, char *format, ...);

/*
** We create a color from r, g and b (considered as char)
** using binary moves to place the correct bits at the right place,
** then we pass that color to printf, and return the allocated string.
*/

char        *ft_rgb2hex(int r, int g, int b)
{
    char            *color_str;

    if (asprintf(&color_str, "#%08x", (r << 16) | (g << 8) | b) < 0)
        return (NULL);
    return (color_str);
}

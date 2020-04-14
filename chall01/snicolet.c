/*
** Needed to compile without warning, see
** https://github.com/nicowilliams/inplace/issues/6
** for details.
*/

#define _GNU_SOURCE 1
#include <stdio.h>


/*
** We create a color from r, g and b (considered as char)
** using binary moves to place the correct bits at the right place,
** then we pass that color to printf, and return the allocated string.
** also a filter of 0-255 validity is added on each color componment
*/

char        *ft_rgb2hex(int r, int g, int b)
{
    char            *color_str;
    unsigned int    color;

	if ((r | g | b) & 0xffffff00)
		return (NULL);
    color = ((r & 0xff) << 16) | ((g & 0xff) << 8) | (b & 0xff);
    if (asprintf(&color_str, "#%06x", color) < 0)
        return (NULL);
    return (color_str);
}

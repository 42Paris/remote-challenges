#include "stdlib.h"

/*
** truncate_color_component:
**
** Ensure an integer is within the range [0, 255],
** truncating it to 0 or 255 if requiered.
*/

static void		truncate_color_component(int *color_component)
{
	if (*color_component < 0)
		*color_component = 0;
	if (*color_component > 255)
		*color_component = 255;
}

/*
** put_color_component_to_hex:
**
** Write a 2 hex digits integer to a string.
*/

static void		put_color_component_to_hex(char *dst, int color_component)
{
	truncate_color_component(&color_component);
	dst[0] = "0123456789abcdef"[color_component / 16];
	dst[1] = "0123456789abcdef"[color_component % 16];
}

/*
** ft_rgb2hex:
**
** Create a string containing the hex representation of a color from
** red, green, and blue components.
*/

char			*ft_rgb2hex(int r, int g, int b)
{
	char		*hex_color;

	hex_color = (char*)malloc(sizeof(char) * 8);
	if (!hex_color)
		return (NULL);
	hex_color[0] = '#';
	put_color_component_to_hex(&hex_color[1], r);
	put_color_component_to_hex(&hex_color[3], g);
	put_color_component_to_hex(&hex_color[5], b);
	hex_color[7] = '\0';
	return (hex_color);
}

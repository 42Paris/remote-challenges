#include <stdlib.h>

void        byte_to_hexa(char *dst, unsigned char byte)
{
	static char *HEXA_BASE="0123456789abcdef";

	dst[0] = HEXA_BASE[byte >> 4];
	dst[1] = HEXA_BASE[byte % 16];
}

char *ft_rgb2hex(int r, int g, int b)
{
	unsigned char	red = r, green = g, blue = b;
	char *hex = NULL;

	if (!(hex = calloc(1, 8)))
		return (NULL);
	hex[0] = '#';
	byte_to_hexa(&hex[1], red);
	byte_to_hexa(&hex[3], green);
	byte_to_hexa(&hex[5], blue);
	return (hex);
}
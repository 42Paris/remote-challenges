#include <stdlib.h>

char *ft_rgb2hex(int r, int g, int b)
{
	char *hex;
	char color;
	char *base = "0123456789abcdef";
	
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (NULL);
	if (!(hex = calloc(8, sizeof(char))))
		return (NULL);
	hex[0] = '#';
	//red
	color = base[r / 16];
	hex[1] = color;
	color = base[r % 16];
	hex[2] = color;
	//green
	color = base[g / 16];
	hex[3] = color;
	color = base[g % 16];
	hex[4] = color;
	//blue
	color = base[b / 16];
	hex[5] = color;
	color = base[b % 16];
	hex[6] = color;
	return (hex);
}

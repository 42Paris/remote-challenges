#include <stdlib.h>

char *ft_rgb2hex(int r, int g, int b)
{
	char *base = "0123456789abcdef";
	
	char *hex;
	if (!(hex = malloc(sizeof(char) * 8)) || r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (0);

	hex[0] = '#';
	hex[1] = base[r / 16];
	hex[2] = base[r % 16];
	hex[3] = base[g / 16];
	hex[4] = base[g % 16];
	hex[5] = base[b / 16];
	hex[6] = base[b % 16];
	hex[7] = 0;

	return hex;
}
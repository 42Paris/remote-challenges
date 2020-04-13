#include <stdlib.h>

char	*ft_rgb2hex(int r, int g, int b)
{
	const char	*s = "0123456789abcdef";
	char		*hex = (char *)malloc(8);

	hex[0] = '#';
	hex[1] = s[r / 16];
	hex[2] = s[r % 16];
	hex[3] = s[g / 16];
	hex[4] = s[g % 16];
	hex[5] = s[b / 16];
	hex[6] = s[b % 16];
	hex[7] = '\0';
	return (hex);
}

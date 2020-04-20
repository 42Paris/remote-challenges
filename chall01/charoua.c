#include <stdlib.h>

char	*ft_rgb2hex(int r, int g, int b)
{
	char *str;
	char *hex;

	hex = "0123456789abcdef";
	if (!(str = malloc(sizeof(char) * 8)))
		return (NULL);
	str[0] = '#';
	str[1] = hex[r / 16];
	str[2] = hex[r % 16];
	str[3] = hex[g / 16];
	str[4] = hex[g % 16];
	str[5] = hex[b / 16];
	str[6] = hex[b % 16];
	str[7] = '\0';
	return (str);
}

#include <stdlib.h>

char	*ft_rgb2hex(int r, int g, int b)
{
	char	*hex;

	r %= 256;
	g %= 256;
	b %= 256;
	hex = (char*)malloc(sizeof(char) * 8);
	if (hex == NULL)
		return (NULL);
	hex[0] = '#';
	hex[1] = r / 16 > 9 ? r / 16 + 'a' - 10 : r / 16 + '0';
	hex[2] = r % 16 > 9 ? r % 16 + 'a' - 10 : r % 16 + '0';
	hex[3] = g / 16 > 9 ? g / 16 + 'a' - 10 : g / 16 + '0';
	hex[4] = g % 16 > 9 ? g % 16 + 'a' - 10 : g % 16 + '0';
	hex[5] = b / 16 > 9 ? b / 16 + 'a' - 10 : b / 16 + '0';
	hex[6] = b % 16 > 9 ? b % 16 + 'a' - 10 : b % 16 + '0';
	hex[7] = '\0';
	return (hex);
}

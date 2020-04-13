#include <stdlib.h>

static int	invalid_rgb(int col)
{
	if (col < 0 || col > 255)
		return (1);
	return (0);
}

char	*ft_rgb2hex(int r, int g, int b)
{
	char		*str;
	const char	*hex = "0123456789abcdef";

	if (invalid_rgb(r) || invalid_rgb(g) || invalid_rgb(b))
		return (NULL);
	if (!(str = malloc(sizeof(char) * 8)))
		return (NULL);
	str[1] = '#';
	str[2] = hex[r / 16];
	str[3] = hex[r % 16];
	str[4] = hex[g / 16];
	str[5] = hex[g % 16];
	str[6] = hex[b / 16];
	str[7] = hex[b % 16];
	str[8] = '\0';
	return (str);
}
#include <stdlib.h>

char	*ft_rgb2hex(int r, int g, int b)
{
	int		i;
	int		n;
	char	*hex;
	char	*base = "0123456789abcdef";

	// Check for errors
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (NULL);

	// Allocate 8 chars
	if (!(hex = calloc(8, sizeof(char))))
		return (NULL);

	// Fill in start and end
	hex[0] = '#';
	hex[7] = '\0';

	// Fill in colors
	n = 256 * 256 * r + 256 * g + b;
	for (i = 6 ; i > 0 ; i--)
	{
		hex[i] = base[n % 16];
		n /= 16;
	}

	return (hex);
}

#include <stdlib.h>

char	*ft_rgb2hex(int r, int g, int b)
{
	char	*hex;
	int	len;
	int	nb;
	int	i;

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (NULL);
	len = 7;
	if (!(hex = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	hex[len] = '\0';
	len--;
	nb = b;
	while (len > 0)
	{
		i = -1;
		while (++i < 2 && len > 0)
		{
			hex[len] = "0123456789abcdef"[nb % 16];
			nb = nb / 16;
			len--;
		}
		nb = (len == 4) ? g : r;
	}
	hex[len] = '#';
	return (hex);
}

#include <stdio.h>
#include <stdlib.h>

size_t	ft_nbrlen(long long n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_to_hex(char **dest, int *pos, int n)
{
	char	*base;
	int		i;

	base = "0123456789abcdef";
	i = 0;
	while (n > 0)
	{
		(*dest)[(*pos)--] = base[(n % 16)];
		n /= 16;
	}
	if ((*pos) % 2 == 1)
		(*dest)[(*pos)--] = '0';
	return ((*dest));
}

char	*ft_rgb2hex(int r, int g, int b)
{
	char	*hex;
	int		pos;

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (NULL);
	if ((hex = malloc(8)) == NULL)
		return (NULL);
	pos = 6;
	hex[0] = '#';
	ft_to_hex(&hex, &pos, b);
	ft_to_hex(&hex, &pos, g);
	ft_to_hex(&hex, &pos, r);
	hex[7] = '\0';
	return (hex);
}

#include <stdlib.h>

char	*ft_rgb2hex(int r, int g, int b)
{
	char	*res;
	int		rgb;
	int		i;
	char	*base = "0123456789abcedf";

	if (r < 0 || r > 255
		|| g < 0 || g > 255
		|| b < 0 || b > 255
		|| !(res = (char *)malloc(sizeof(char) * 8)))
		return (NULL);
	rgb = r << 16 | g << 8 | b;
	res[0] = '#';
	res[7] = 0;
	i = 7;
	while (--i)
	{
		res[i] = base[rgb & 0xf];
		rgb >>= 4;
	}
	return (res);
}

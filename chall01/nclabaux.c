#include <stdio.h>
#include <stdlib.h>

char	ft_dec2hex(int i)
{
	if (i > 9)
		return (i + 87);
	return (i + 48);
}

char	*ft_rgb2hex(int r, int g, int b)
{
	char	*result;

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (NULL);
	if(!(result = malloc(sizeof(char) * 8)))
		return (NULL);
	result[0] = '#';
	result[1] = ft_dec2hex(r / 16);
	result[2] = ft_dec2hex(r % 16);
	result[3] = ft_dec2hex(g / 16);
	result[4] = ft_dec2hex(g % 16);
	result[5] = ft_dec2hex(b / 16);
	result[6] = ft_dec2hex(b % 16);
	result[7] = 0;
	return (result);
}
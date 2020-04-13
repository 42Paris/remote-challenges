#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_itoh(int value)
{
	int		i;
	int		n;
	char	*str;
	char	*hex;

	hex = "0123456789abcdef";
	i = 1;
	n = value;
	while (n /= 16)
		i++;
	if (!(str = (char *)calloc(sizeof(char), i + 1)))
		return (NULL);
	str[i] = 0;
	if (value == 0)
		str[0] = '0';
	n = value;
	while (n)
	{
		str[--i] = hex[n % 16];
		n /= 16;
	}
	if (strlen(str) == 1) {
		str[1] = str[0];
		str[0] = '0';
	}
	return (str);
}

char *ft_rgb2hex(int r, int g, int b)
{
	char *hex = (char *)calloc(sizeof(char), 8);

	char *p1 = ft_itoh(r);
	char *p2 = ft_itoh(g);
	char *p3 = ft_itoh(b);

	hex[0] = '#';
	hex[1] = p1[0];
	hex[2] = p1[1];
	hex[3] = p2[0];
	hex[4] = p2[1];
	hex[5] = p3[0];
	hex[6] = p3[1];

	return hex;
}

int		main(int argc, char **argv)
{
	assert(strcmp(ft_rgb2hex(252, 186, 3), "#fcba03") == 0);
	assert(strcmp(ft_rgb2hex(255, 255, 255), "#ffffff") == 0);
	assert(strcmp(ft_rgb2hex(0, 0, 0), "#000000") == 0);
	assert(strcmp(ft_rgb2hex(21, 42, 137), "#152a89") == 0);

	return (0);
}

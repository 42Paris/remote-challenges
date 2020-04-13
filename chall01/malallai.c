#include <stdio.h>
#include <stdlib.h>

char	*ft_strcpy(char *dest, const char *src, int start)
{
	int		i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (src[i])
		dest[start++] = src[i++];
	return (dest);
}

char	*str_new(int size)
{
	char	*str = malloc(sizeof(char *) * size);
	if (!str)
		return NULL;
	str = ft_strcpy(str, "00", 0);
	str[size] = 0;
	return str;
}

char	*itoh(int value)
{
	char	*hex = "0123456789abcdef";
	int		i = 2;
	int		n = value;
	char	*str = NULL;

	if (value < 0 || value > 255)
		return NULL;
	if (!(str = str_new(i)))
		return NULL;
	if (!value)
		return str;
	while (n)
	{
		str[--i] = hex[n % 16];
		n /= 16;
	}
	return str;
}

char *ft_rgb2hex(int r, int g, int b)
{
	char	*new = str_new(7);
	char	*strR = itoh(r);
	char	*strG = itoh(g);
	char	*strB = itoh(b);

	ft_strcpy(new, "#", 0);
	ft_strcpy(new, strR, 1);
	ft_strcpy(new, strG, 3);
	ft_strcpy(new, strB, 5);
	new[7] = 0;
	return new;
}

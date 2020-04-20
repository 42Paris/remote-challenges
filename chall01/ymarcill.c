#include "string.h"
#include "stdlib.h"
#include "stdio.h"

char	*concat_3(char *s1, char *s2, char *s3)
{
	int		i;
	int		y;
	char	*dst;

	i = 0;
	y = 0;
	dst = malloc(sizeof(char) * (strlen(s1) + strlen(s2) + strlen(s3) + 4));
	dst[i++] = '#';
	if (strlen(s1) < 2)
		dst[i++] = '0';
	if (strlen(s1) < 1)
		dst[i++] = '0';
	while (s1[y])
		dst[i++] = s1[y++];
	if (strlen(s2) < 2)
		dst[i++] = '0';
	if (strlen(s2) < 1)
		dst[i++] = '0';
	y = 0;
	while (s2[y])
		dst[i++] = s2[y++];
	if (strlen(s3) < 2)
		dst[i++] = '0';
	if (strlen(s3) < 1)
		dst[i++] = '0';
	y = 0;
	while (s3[y])
		dst[i++] = s3[y++];
	dst[i] = '\0';
	return (dst);	
}

int	ft_hlen(int i)
{
	int	s;

	s = 0;
	while (i > 0)
	{
		i = i / 16;
		s++;
	}
	return (s);
}

char	*i2h2a(int r)
{
	char	*hex;
	char	*s1;
	int		i;

	i = ft_hlen(r);
	hex = "0123456789abcdef";
	s1 = malloc(sizeof(char) * (i));
	s1[i] = '\0';
	i--;
	while (r > 0)
	{
		s1[i] = hex[r % 16];
		r = r / 16;
		i--;
	}
	return (s1);
}

char *ft_rgb2hex(int r, int g, int b)
{
	char	*s1;
	char 	*s2;
	char 	*s3;
	char	*dst;

	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return ("r, g, b only between 0 and 255");
	s1 = i2h2a(r);
	s2 = i2h2a(g);
	s3 = i2h2a(b);
	dst = concat_3(s1, s2, s3);
	return (dst);
}

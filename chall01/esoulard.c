#include <stdio.h>
#include <stdlib.h>

char *ft_rgb2hex(int r, int g, int b)
{
	char *buf;

	if (!(buf = malloc(60)))
		return (NULL);
	sprintf(buf, "#%02x%02x%02x", r, g, b);
	return (buf);
}

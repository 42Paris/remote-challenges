#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ft_rgb2hex(int r, int g, int b)
{
	unsigned long	rgb;
	char		*str;

	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return (NULL);
	if (!(str = (char*)malloc(sizeof(char) * 8)))
		return (NULL);
	rgb = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	sprintf(str,"#%06lx", rgb);
	return (str);
}

#include <stdlib.h>

void int2hex(int n, char *hex)
{
	char *nbs = "0123456789abcdef";
	char *res;
	int i;

	i = 0;
	while (n > 15)
	{
		n -= 16;
		i++;
	}
	hex[0] = nbs[i];
	i = 0;
	while (n > 0)
	{
		n -= 1;
		i++;
	}
	hex[1] = nbs[i];
}

char *ft_rgb2hex(int r, int g, int b)
{
	char *hex;
	
	if (r >= 0 && g >= 0 && b >= 0)
	{
		if ((hex = (char *)malloc(8)) == NULL)
			return(NULL);
		hex[0] = '#';
		int2hex(r, hex+1);
		int2hex(g, hex+3);
		int2hex(b, hex+5);
		hex[7] = '\0';
		return(hex);
	}
	return(NULL);
}

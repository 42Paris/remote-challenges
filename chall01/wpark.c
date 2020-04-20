#include <string.h>
#include <stdlib.h>

int is_rgv(int num)
{
	if (num < 0 || num > 255)
		return (0);
	return (1);
}

char *rgb2hex(int n, char *buff)
{
	char *s = "0123456789abcdef";

	buff[0] = s[n / 16];
	buff[1] = s[n % 16];
	buff[2] = '\0';
	return (buff);
}

char *hv_rgb2hex(int r, int g, int b)
{
	char *res;
	char buff[3];

	if (!is_rgv(r) || !is_rgv(g) || !is_rgv(b))
		return (NULL);
	if (!(res = calloc(8, sizeof(char))))
		return (NULL);
	res[0] = '#';
	strcat(res + 1, rgb2hex(r, buff));
	strcat(res + 3, rgb2hex(g, buff));
	strcat(res + 5, rgb2hex(b, buff));
	return (res);
}

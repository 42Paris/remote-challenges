#include <stdio.h>
#include <string.h>

char *ft_rgb2hex(int r, int g, int b);

int main()
{
	printf("%s\n", ft_rgb2hex(255, 255, 255));
	return 0;
}

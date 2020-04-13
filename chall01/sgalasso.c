#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char	*inttohex(int val) {
   	char *str;
	char tab[] = "0123456789abcdef";

	if (!(str = malloc(3)))
		return (0);
   	bzero(str, 3);
   	for (int i = 2; i > 0; val >>= 4)
      		str[--i] = tab[val&0xF];
   	return str;
}

static char	*ft_rgb2hex(int r, int g, int b) {
	char *hex = malloc(7);
	sprintf(hex, "#%s%s%s", inttohex(r), inttohex(g), inttohex(b));
	return (hex);
}

/*int main(void) {
	printf("%s", ft_rgb2hex(252, 186, 3));
}*/

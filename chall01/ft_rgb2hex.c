#include <stdlib.h>

//Convert half-octet into hex char
char	val2hex(char val)
{
	return (val < 10 ? val + '0' : val - 10 + 'a');
}

//Get every half-octet
char	*ft_rgb2hex(int r, int g, int b)
{
	char	*result = NULL;

	result = malloc(8);
	result[0] = '#';
	result[1] = val2hex((r >> 4) & 0xF);
	result[2] = val2hex(r & 0xF);
	result[3] = val2hex((g >> 4) & 0xF);
	result[4] = val2hex(g & 0xF);
	result[5] = val2hex((b >> 4) & 0xF);
	result[6] = val2hex(b & 0xF);
	result[7] = '\0';
	return (result);
}

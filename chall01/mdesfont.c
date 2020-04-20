#include <stdlib.h>
#include <string.h>

char	*ft_itoa_base(int num, char *hexa)
{
	int					count;
	unsigned int		tmp;
	char				*res;
	unsigned int		base_length;

	base_length = strlen(hexa);
	count = 1;
	tmp = num;
	while (tmp >= base_length && (tmp /= base_length))
		++count;
	tmp = num;
	if (!(res = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	res[count] = '\0';
	while (tmp >= base_length)
	{
		--count;
		res[count] = hexa[tmp % base_length];
		tmp /= base_length;
	}
	res[--count] = hexa[tmp % base_length];
	free(res);
	return (res);
}


char	*ft_rgb2hex(int r, int g, int b)
{
	char	*str;
	char	*hexa;

	hexa = "0123456789ABCDEF";
	if ((r < 0 && r > 255) || (g < 0 && g > 255) || (b < 0 && b > 255))
		return (NULL);
	
	if (!(str = malloc((sizeof(char) * 8))))
		return (0);
	str[0] = '#';
	str[1] = *ft_itoa_base(r, hexa);
	str[2] = *ft_itoa_base(r % 16, hexa);
	str[3] = *ft_itoa_base(g, hexa);
	str[4] = *ft_itoa_base(g % 16, hexa);
	str[5] = *ft_itoa_base(b, hexa);
	str[6] = *ft_itoa_base(b % 16, hexa);
	str[7] = '\0';
	free(str);
	return (str);
}

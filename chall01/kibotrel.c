#include <stdlib.h>
#include <string.h>

unsigned int	ft_numlen(long value, int base)
{
	int	size;

	size = 1;
	if (base != 10 && value < 0)
		value = -value;
	if (value < 0)
		size++;
	while (value / base)
	{
		size++;
		value /= base;
	}
	return (size);
}

char	*ft_itoa_base(int value, int base)
{
	int				size;
	long			nbr;
	char			*result;
	char			*ref_base;

	nbr = value;
	ref_base = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	size = ft_numlen(nbr, base);
	if (!(result = (char*)malloc(sizeof(*result) * (size + 1))))
		return (NULL);
	result[size--] = '\0';
	result[0] = (value < 0 ? '-' : '0');
	if (value < 0)
		nbr = -nbr;
	while (nbr > 0)
	{
		result[size--] = ref_base[nbr % base];
		nbr /= base;
	}
	return (result);
}

char	*ft_rgb2hex(int r, int g, int b)
{
	char	*color;
	char	*hex;
	int		size;

	color = ft_itoa_base(((r << 16) | (g << 8) | b), 16);
	size = strlen(color);

	if (!(hex = malloc(sizeof(char) * (size + 2))))
		return (NULL);
	for (int i = 1; i < size + 1; i++)
		hex[i] = color[i - 1];
	hex[0] = '#';
	hex[size + 1] = '\0';
	free(color);
	return (hex);
}

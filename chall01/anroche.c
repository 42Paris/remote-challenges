#include <stdio.h>
#include <stdlib.h>

char	*ft_charconcat(char *src, char c);

int		len(char *str)
{
	int i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	dest = ft_charconcat(dest, src[0]);
	dest = ft_charconcat(dest, src[1]);
	return (dest);
}

char	*ft_charconcat(char *src, char c)
{
	char	*dest;
	int	i;

	i = 0;
	dest = (char*)malloc(sizeof(len(src) + 2));
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	
	dest[i++] = c;
	dest[i] = '\0';
	return (dest);
}

char *ft_invert_string(char *src)
{
	char *ret;
	int i;
	i = len(src);
	ret = "";
	while (i >= 0)
	{
		ret = ft_charconcat(ret, src[i]);
		i--;
	}
	return (ret);
}

char	*itoa_hex(int val)
{
	char	*ret;
	char	*tab_hex = "0123456789abcdef";
	
	ret = "";
	if (val < 0)
		val = 0;
	if (val > 255)
		val = 255;
	while (val > 16)
	{
		ret = ft_charconcat(ret, tab_hex[val % 16]);
		val = val / 16;
	}
	ret = ft_charconcat(ret, tab_hex[val % 16]);
	if (len(ret) < 2)
	{
		ret = ft_charconcat(ret, '0');
	}
	ret = ft_invert_string(ret);
	return (ret);
}

char *ft_rgb2hex(int r, int g, int b)
{	
	char	*str_hex;

	str_hex = "#";

	str_hex = ft_strcat(str_hex, itoa_hex(r));
	str_hex = ft_strcat(str_hex, itoa_hex(g));
	str_hex = ft_strcat(str_hex, itoa_hex(b));
	return (str_hex);
}

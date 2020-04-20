//#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <assert.h>

void	convert_base(int n, char *result, int i)
{
	int remind;

	remind = n;
	if (n <= 16)
	{
		result[i] = '0';
		i++;
	}
	while (n != 0)
	{
		remind = n % 16;
		if ( remind < 10)
			remind = remind + 48;
		else
			remind = remind + 55;
		result[i] = remind;
		i++;
		n = n / 16;
	}
}

char	*ft_rgb2hex(int r, int g, int b)
{
	int i;
	char *result;
	
	if (!(result = malloc(sizeof(char) * 8)))
		return (0);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0|| b > 255))
		return (0);
	i = 0;
	result[i] = '#';
	i++;
	convert_base(r, result, i);
	i+=2;
	convert_base(g, result, i);
	i+=2;
	convert_base(b, result, i);
	result[8]= '\0';
	return (result);
}

//int		main()
//{
//	printf("hex: %s\n", ft_rgb2hex(12, 265, 12));
//	return (0);
//}

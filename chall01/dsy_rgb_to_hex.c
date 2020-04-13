#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/*
** Utility functions
*/
static int	check_rgb(int n)
{
	if (n > 255 || n < 0)
		return (0);
	else
		return (1);
}

static char*	leak(char *to_free)
{
	free(to_free);
	return (NULL);
}

/*
** Core
*/

static char	*invert_2_by_2(char *s)
{
	char	tmp;
	int	i;

	i = 1;
	while (s[i] && s[i + 1])
	{
		tmp = s[i];
		s[i] = s[i + 1];
		s[i + 1] = tmp;
		i += 2;
	}
	return (s);
}

static char*	int255_to_hex(int r, int g, int b, char *res)
{
	char	*base_16 = "0123456789abcdef";
	int	i = 1;

	res[0] = '#';
	res[2] = '0';
	res[4] = '0';
	res[6] = '0';
	while (r)
	{
		res[i++] = base_16[r % 16];
		r /= 16;
	}
	i = 3;
	while (g)
	{
		res[i++] = base_16[g % 16];
		g /= 16;
	}
	i = 5;
	while (b)
	{
		res[i++] = base_16[b % 16];
		b /= 16;
	}
	return (invert_2_by_2(res));
}

/*
** Driver function
*/

char		*ft_rgb2hex(int r, int g, int b)
{
	int	i;
	char	*hex;
	if (!check_rgb(r) || !check_rgb(g) || !check_rgb(b))
		return (NULL);
	if(!(hex = (char*)malloc(sizeof(char) * 8)))
		return (leak(hex));
	return (int255_to_hex(r, g, b, hex));
}

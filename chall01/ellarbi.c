#include <stdlib.h>
#include <string.h>

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	i;
	size_t	lens1;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	lens1 = strlen(s1);
	if (!(new_str = malloc(strlen(s1) + strlen(s2) + 1)))
		return (NULL);
	while (s1[++i])
		new_str[i] = s1[i];
	i = -1;
	while (s2[++i])
		new_str[lens1 + i] = s2[i];
	new_str[lens1 + i] = '\0';
	return (new_str);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int i;
	int j = 0;
	int *res = malloc(sizeof(int) * 8);
	char *end = malloc(8);

	i = 0;
	while (nbr)
	{
		res[i] = nbr % 16;
		nbr = nbr / 16;
		i++;
	}
	while (--i >= 0)
	{
		if (0 <= res[i] && res[i] <= 9)
		{
			end[j] = '0';
			j++;
		}
		end[j] = base[res[i]];
		j++;
	}
	return end;
}

char *ft_rgb2hex(int r, int g, int b)
{
	char *end = malloc(8);
	end[0] = '#';
	end = ft_strjoin(end, ft_putnbr_base(r, "0123456789abcdef"));
	end = ft_strjoin(end, ft_putnbr_base(g, "0123456789abcdef"));
	end = ft_strjoin(end, ft_putnbr_base(b, "0123456789abcdef"));
	return end;
}
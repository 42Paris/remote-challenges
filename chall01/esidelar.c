#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_add_char(char *s1, char const s2)
{
	unsigned int	i;
	char			*str;

	i = strlen(s1);
	if (!(str = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i] = s2;
	str[++i] = '\0';
	free(s1);
	return (str);
}

static int		lenerint(int n, char *base)
{
	long long	len;

	len = 0;
	if (n >= 0 && n <= 9)
		return (1);
	else if (n == -2147483648)
		return (11);
	while (n)
	{
		n /= strlen(base);
		len++;
	}
	return (len);
}

char			*ft_itoa_base(long int n, char *base)
{
	char				*str;
	unsigned long int	tp;
	int					len;

	tp = (unsigned long int)n;
	len = lenerint(tp, base);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = base[tp % strlen(base)];
		tp /= strlen(base);
	}
	return (str);
}

void			sj_free_s1_or_s2(char *s1, char *s2, int fre)
{
	if (fre == 1)
	{
		free(s1);
		s1 = NULL;
	}
	if (fre == 2)
	{
		free(s2);
		s2 = NULL;
	}
}

char			*ft_strjoin(char *s1, char *s2, int fre)
{
	unsigned int	i;
	unsigned int	y;
	char			*str;

	if (!s1 || !s2)
		return (NULL);
	i = strlen(s1);
	y = strlen(s2);
	if (!(str = (char *)malloc(sizeof(char) * i + y + 1)))
		return (NULL);
	i = 0;
	y = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[y])
		str[i++] = s2[y++];
	str[i] = '\0';
	sj_free_s1_or_s2(s1, s2, fre);
	return (str);
}

char	*color(int nb_c, char *str)
{
	char *tb;
	char *noob;
	int i = 0;

	tb = ft_itoa_base(nb_c, "0123456789abcdef");
	i = strlen(tb);
	while (i < 2)
	{
		tb = ft_strjoin("0", tb, 2);
		i++;
	}
	noob = ft_strjoin(str, tb, 3);
	return (noob);
}

char *ft_rgb2hex(int r, int g, int b)
{
	char *str = strdup("");

	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
	{
		free(str);
		return (NULL);
	}
	str = ft_add_char(str, '#');
	str = color(r, str);
	str = color(g, str);
	str = color(b, str);
	if (strlen(str) != 7)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

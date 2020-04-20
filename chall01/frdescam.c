#include <stdlib.h>
#include <string.h>

static int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char		*ft_strrev(char *str)
{
	int		size;
	int		i;
	char	tmp;

	size = ft_strlen(str);
	size--;
	i = 0;
	while (i < size)
	{
		tmp = str[i];
		str[i] = str[size];
		str[size] = tmp;
		i++;
		size--;
	}
	return (str);
}

static int		ft_malloc(char **nb_c, int *sign, long *nb_l, int *nb)
{
	if (!(*nb_c = (char *)malloc(sizeof(char) * 40)))
		return (0);
	*sign = 1;
	if (*nb == 0)
		(*nb_c)[0] = '0';
	if (*nb < 0)
	{
		*nb_l = *nb;
		*nb_l *= -1;
		*sign = -1;
	}
	else
		*nb_l = *nb;
	return (1);
}

char			*ft_itoa_base(int nb, const char *base)
{
	long	nb_l;
	char	*nb_c;
	int		base_divider;
	int		i;
	int		sign;

	if (!(ft_malloc(&nb_c, &sign, &nb_l, &nb)))
		return (0);
	base_divider = ft_strlen((char *)base);
	if (nb_c[0] == '0')
		i = 1;
	else
		i = 0;
	while (nb_l > 0)
	{
		nb_c[i++] = base[nb_l % base_divider];
		nb_l /= base_divider;
	}
	if (sign == -1)
		nb_c[i++] = '-';
	nb_c[i] = '\0';
	return (ft_strrev(nb_c));
}

char	*ft_rgb2hex(int r, int g, int b)
{
	char	*r_c;
	char	*g_c;
	char	*b_c;
	char	*out;
	int	i;

	r_c = ft_itoa_base(r, "0123456789abcdef");
	g_c = ft_itoa_base(g, "0123456789abcdef");
	b_c = ft_itoa_base(b, "0123456789abcdef");
	if (!(out = malloc(sizeof(char) * 8)))
		return (NULL);
	out[0] = '#';
	i = 1;
	if ((ft_strlen(r_c) == 1))
	{
		out[i] = '0';
		i++;
	}
	strncpy(&(out[i]), r_c, 2);
	i = 3;
	if ((ft_strlen(g_c) == 1))
	{
		out[i] = '0';
		i++;
	}
	strncpy(&(out[i]), g_c, 2);
	i = 5;
	if ((ft_strlen(b_c) == 1))
	{
		out[i] = '0';
		i++;
	}
	strncpy(&(out[i]), b_c, 3);
	free(r_c);
	free(g_c);
	free(b_c);
	return (out);
}
/*
**#include <stdio.h>
**
**int		main(void)
**{
**	char	*str;
**
**	str = ft_rgb2hex(255, 255, 255);
**	printf("%s\n", str);
**	free(str);
**}
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*str;
	char			*temp_s1;

	i = 0;
	j = 0;
	temp_s1 = s1;
	while (s1 && s1[i])
		i++;
	while (s2 && s2[j])
		j++;
	if (!(str = malloc(sizeof(char*) * (i + j + 1))))
		return (0);
	while (s1 && *temp_s1)
		*str++ = *temp_s1++;
	while (s2 && *s2)
		*str++ = *s2++;
	*str = 0;
	return (str - i - j);
}

void		ft_char_nbr(char *str, long n, int lg_n)
{
	str[lg_n] = 0;
	while (n > 9)
	{
		str[--lg_n] = n % 10 + '0';
		n = n / 10;
	}
	str[0] = n % 10 + '0';
}

int			ft_lg_n(int n)
{
	int	i;

	i = 0;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

char		*ft_itoa(int n)
{
	int			i;
	long		n_n;
	char		*str;
	int			sign;
	int			lg_n;

	i = 0;
	sign = 0;
	lg_n = ft_lg_n(n);
	n_n = n;
	if (n < 0)
	{
		sign = 1;
		n_n = -1 * n_n;
	}
	if (!(str = malloc(sizeof(char) * (lg_n + sign + 1))))
		return (0);
	if (sign == 1)
	{
		str[i] = '-';
		i++;
	}
	ft_char_nbr(&str[i], n_n, lg_n);
	return (str);
}

int		ft_check_str(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int		ft_isspace(char str)
{
	return (str == '\t' || str == '\n' || str == '\v'
			|| str == '\r' || str == ' ' || str == '\f');
}

int		check_b(char *base)
{
	int		i;
	int		j;

	i = 0;
	while (base[i])
	{
		j = 1;
		if (ft_isspace(base[i]) || base[i] == '+' || base[i] == '-')
			return (-1);
		while (base[j + i])
		{
			if (base[i] == base[j + i])
				return (-1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (-1);
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int				i;
	int				sign;
	int				nb;
	int				b_length;
	int				c;

	i = 0;
	sign = 1;
	nb = 0;
	b_length = check_b(base);
	while (ft_isspace(str[i]))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] && (c = ft_check_str(str[i], base)) != -1)
	{
		nb = (nb * b_length) + c;
		i++;
	}
	return (nb * sign);
}

void	ft_nb_zero(char *base_to, char *new_base)
{
	new_base[0] = base_to[0];
	new_base[1] = '\0';
}

int		ft_count_malloc(int nb, int lg_base)
{
	int count;

	count = 0;
	while (nb != 0)
	{
		nb = nb / lg_base;
		count++;
	}
	return (count);
}

int		ft_convnbr_base(long nbr, int lg_nb, char *base_to, char *new_base)
{
	int		lg_base;

	lg_base = check_b(base_to);
	if (nbr >= lg_base)
		ft_convnbr_base(nbr / lg_base, lg_nb - 1, base_to, new_base);
	new_base[lg_nb - 1] = base_to[nbr % lg_base];
	return (*new_base);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nb;
	int		lg_base_to;
	int		lg_nb;
	char	*new_base;

	if ((lg_base_to = check_b(base_to)) == -1 || check_b(base_from) == -1)
		return (0);
	if ((nb = ft_atoi_base(nbr, base_from)) == 0)
	{
		new_base = malloc(sizeof(*new_base) * 2);
		ft_nb_zero(base_to, new_base);
		return (new_base);
	}
	lg_nb = ft_count_malloc(nb, lg_base_to);
	if (!(new_base = malloc(sizeof(*new_base) * (lg_nb + 2))))
		return (0);
	if (nb < 0)
	{
		new_base[0] = '-';
		lg_nb++;
		nb = -nb;
	}
	ft_convnbr_base(nb, lg_nb, base_to, new_base);
	new_base[lg_nb] = '\0';
	return (new_base);
}

int		ft_RGB_to_int(int r, int g, int b)
{
	return(b + 256 * g + 65536 * r);
}

char *ft_rgb2hex(int r, int g, int b)
{
	char *hexa_nb;
	char *tmp;
	char *char_int;

	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return (NULL);
	if (!(char_int = ft_itoa(ft_RGB_to_int(r, g, b))) ||
	!(tmp = ft_convert_base(char_int, "0123456789", "0123456789abcdef")))
		return (NULL);
	if (!(hexa_nb = ft_strjoin("#", tmp)))
		return(NULL);
	free(char_int);
	free(tmp);
	return(hexa_nb);
}

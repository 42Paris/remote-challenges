#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] && i < n)
	{
		if (s1[i] != s2[i])
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	if (s2[i] == '\0' || i == n)
		return (0);
	else
		return (-s2[i]);
}

int		move_letter(char **str, int len)
{
	char 	*tmp;
	int		i;

	if (!(tmp = malloc(sizeof(char) * (len + 1))))
		return (-1);
	i = 1;
	while (i < len)
	{
		tmp[i - 1] = (*str)[i];
		i++;
	}
	tmp[len - 1] = (*str)[0];
	tmp[len] = '\0';
	*str = tmp;
	return (1);
}

int		ft_necklace(char *s1, char *s2)
{
	int	len_s1;
	int	len_s2;
	int	i;

	if (!s1 || !s2)
		return (-1);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (len_s1 != len_s2)
		return (0);
	i = 0;
	while (i < len_s1)
	{
		if (!ft_strncmp(s1, s2, len_s1))
			return (1);
		if (!move_letter(&s1, len_s1))
			return (-1);
		i++;
	}
	if (!*s1 && !*s2)
		return (1);
	return (0);
}
/*
**#include <stdio.h>
**
**int	main(int argc, char **argv)
**{
**	(void)argc;
**	printf("%d\n", ft_necklace(argv[1], argv[2]));
**}
*/

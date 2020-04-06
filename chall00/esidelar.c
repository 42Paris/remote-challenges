#include <string.h>
#include <stdio.h>
#include <stdlib.h>

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
	return (str);
}


int		ft_necklace(char *s1, char *s2)
{
	int		i;
	char	*str;
	char	*temp;

	i = 0;
	if ((!s1 && !s2) || (!strlen(s1) && !strlen(s2)))
		return (1);
	else if (!s1 || !s2)
		return (0);
	i = strlen(s1);
	str = strdup(s1);
	while (i)
	{
		if (!strcmp(str, s2))
			return (1);
		temp = ft_add_char(str + 1, str[0]);
		free(str);
		str = strdup(temp);
		free(str);
		i--;
	}
	return (0);
}

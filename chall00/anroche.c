#include <stdlib.h>

char	*front_to_back(char	*s1);

int	compare_str(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1 != '\0' && *s2 != '\0')
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

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

int ft_necklace(char *s1, char *s2)
{	
	int len1;
	
	len1 = len(s1);
	if (len1 == len(s2))
	{	
		if (len1 == 0)
			return (1);
		while (len1 > 0)
		{
			if (compare_str(s1, s2) == 0)
				return 1;
			len1--;
			s1 = front_to_back(s1);
		}
		return 0;
	}
	return 0;
}

char	*front_to_back(char *s1)
{
	int i = len(s1);
	char *ret;
	int index;
	
	index = 1;
	if ((ret = (char*)malloc(sizeof(i + 1))) == NULL)
		return NULL;
	while (s1[index])
	{
		ret[index - 1] = s1[index];
		index++;
	}
	ret[--index] = s1[0];
	ret[++index] = '\0';
	return (ret);
}

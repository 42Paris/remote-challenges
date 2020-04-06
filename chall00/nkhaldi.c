#include <string.h>

int ft_nakelace(char *s1, char *s2)
{
	int ret = 0;
	int i = 0;
	int j = 0;

	if (strlen(s1) != strlen(s2))
		return ret;
	if (!strcmp(s1, "") && !strcmp(s2, ""))
		return (ret = 1);
	while (i < strlen(s1))
	{
		if (s1 && (s1[i] == s2[j]))
		{
			j++;
			ret = 1;
		}
		else
		{
			ret = 0;
		}
		i++;
	}

	return (ret);
}

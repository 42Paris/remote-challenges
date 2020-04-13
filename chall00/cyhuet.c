#include <string.h>
#include <stdlib.h>
#include <stdio.h>

static char	*shift_char(char *s1)
{
	char *ret = malloc(strlen(s1) + 1);
	char front;
	int i;

	front = *s1;
	for (i = 0; i < strlen(s1) - 1; i++)
	{
		ret[i] = s1[i + 1];
	}
	ret[i++] = front;
	ret[i] = 0;
	return ret;
}

int ft_necklace(char *s1, char *s2)
{
	s1 = strdup(s1);
	if (strlen(s1) != strlen(s2))
		return 0;
	if (strlen(s1) == 0 && strlen(s2) == 0)
		return (1);
	for (int i = 0; i < strlen(s1); i++)
	{
		char *tmp = s1;
		s1 = shift_char(s1);
		free(tmp);
		if (strcmp(s1, s2) == 0)
		{
			free(s1);
			return (1);
		}
	}
	free(s1);
	return (0);
}

int main()
{
	ft_necklace("nicole", "icolen");
	return 0;
}

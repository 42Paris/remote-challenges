#include <string.h>

char *ft_decal(char *s1)
{
	char *dup = strdup(s1);

	int i = 0;
	int len = strlen(s1);
	while (i < len - 1)
	{
		dup[i] = s1[i + 1];
		++i;
	}
	dup[i] = s1[0];
	return (dup);
}

int ft_necklace(char *s1, char *s2)
{
	char *str = strdup(s1);

	int i = 0;
	int len = strlen(s1);
	if (len == 0)
		return (1);
	while (i < len)
	{
		str = ft_decal(str);
		if (!strcmp(s2, str))
			return (1);
		++i;
	}
	return (0);
}

/*
#include <assert.h>
int		main(int argc, char **argv)
{
	assert(ft_necklace("nicole", "icolen") == 1);
	assert(ft_necklace("nicole", "lenico") == 1);
	assert(ft_necklace("nicole", "coneli") == 0);
	assert(ft_necklace("aabaaaaabaab", "aabaabaabaaa") == 1);
	assert(ft_necklace("abc", "cba") == 0);
	assert(ft_necklace("xxyyy", "xxxyy") == 0);
	assert(ft_necklace("xyxxz", "xxyxz") == 0);
	assert(ft_necklace("x", "x") == 1);
	assert(ft_necklace("x", "xx") == 0);
	assert(ft_necklace("x", "") == 0);
	assert(ft_necklace("", "") == 1);
	return (0);
}
*/

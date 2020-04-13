#include <stdio.h>
#include <string.h>

int solver(char *s1, char *s2, int i, int s2len)
{
	char s3[s2len];
	bzero(s3, s2len);
	strcpy(s3, &s2[s2len - i]);
       	strcpy(&s3[i], s2);
	s3[s2len] = '\0';
	return (strcmp(s1, s3) == 0 ? 1 : 0);
}

int ft_necklace(char *s1, char *s2)
{
	int s1len = !s1 ? 0 : strlen(s1);
	int s2len = !s2 ? 0 : strlen(s2);
	int i = 0;
	if (s1len != s2len)
		return 0;
	while (i < s1len)
	{
		if (s1[i] == s2[0])
			if (solver(s1, s2, i, s2len) == 1)
				return 1;
		++i;
	}
	return s1len + s2len == 0 ? 1 : 0;
}

int main(void)
{
	printf("%d\n", ft_necklace("nicole","icolen"));
	printf("%d\n", ft_necklace("nicole","lenico"));
	printf("%d\n", ft_necklace("nicole","coneli"));
	printf("%d\n", ft_necklace("aabaaaaabaab","aabaabaabaaa"));
	printf("%d\n", ft_necklace("abc","cba"));
	printf("%d\n", ft_necklace("xxyyy","xxxyy"));
	printf("%d\n", ft_necklace("xyxxz","xxyxz"));
	printf("%d\n", ft_necklace("x","x"));
	printf("%d\n", ft_necklace("x","xx"));
	printf("%d\n", ft_necklace("x",""));
	printf("%d\n", ft_necklace("",""));
}

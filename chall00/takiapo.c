#include <assert.h>
int ft_necklace(char *s1, char *s2){

	int	i;
	char	al1[512];
	char	al2[512];

	if (!s1 && !s2 || !*s1 && !*s2)
		return 1;
	if (!s1 || !s2){
		return 0;
	}
	i = 0;
	while (i < 512)
	{
		al1[i] = 0;
		al2[i] = 0;
		i++;
	}
	i = 0;
	while (s1[i] && s2[i]){
		al1[s1[i]] += 1;
		al2[s2[i]] += 1;
		i++;
	}
	if (s1[i] || s2[i])
		return 0;
	i = 0;
	while (i < 512)
	{
		if (al1[i] != al2[i]){
			return 0;
		}
		i++;
	}
	return 1;
}

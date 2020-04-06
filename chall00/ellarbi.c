#include <string.h>
#include <stdlib.h>

int		ft_necklace(char *s1, char *s2)
{
	int lens1 = strlen(s1);
	int lens2 = strlen(s2);
	int res;
	char *strtotal = malloc((lens1 * 2) + 1); 		// On malloc la chaine pour copier 2 fois s1 dedans

	if (lens1 != lens2)
		return 0;
	strcpy(strtotal, s1);					// On copie 2 fois
	strcpy(strtotal + lens1, s1);				// s1 dans strtotal
	res = (int)strstr(strtotal, s2);
	if (res == 0)
		return 0;					// On return 0
	else							// ou 1 selon si strstr
		return 1;					// pointe sur null ou pas
}
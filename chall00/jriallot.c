#include <string.h>

/**
 * Pour résoudre le problème, j'ai décider de partir d'une base de parcourt
 * complet d'une liste. J'ai donc une liste qui sera parcourru dans son
 * intégralité, et ce depuis son preier caractère, et le deuxième suit la même
 * logique mais, en décalant l'indice de début a chaque fois.
 */
int ft_necklace(char *s1, char *s2) {
    size_t	i;
    size_t	j;
	int		ret;

    if (strlen(s1) != strlen(s2))
		return (0);
    i = -1;
	ret = 1;
    while (++i < strlen(s2))
	{
		ret = 1;
		j = -1;
		while (++j < strlen(s2) && ret)
		{
			if (s1[j] != s2[(i + j) % strlen(s2)])
				ret = 0;
		}
		if (ret)
			return (ret);
	}
	return (ret);
}
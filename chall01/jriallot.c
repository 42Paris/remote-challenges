#include <stdlib.h>

/**
 * Pour résoudre ce problème j'ai décider de créer une chaine de caractère
 * que je remplis d'abord d'un # puis de la correspondance hexa décimale des entiers
 * grâce aux calculs de modulaux et de division entière. j'utilise les opérateurs
 * ternaires pour le choix de la variable utilisé dans le calcul et le choix du type
 * de caractère a intégrer a la chaine (décimal ou alphabétique).
 */
char	*ft_rgb2hex(int r, int g, int b) {
	char	*str;
	int		i = 0;

    if (!(str = malloc(sizeof(*str) * 8)))
    
	if (r > 255)
		r = 255;
	else if (r < 0)
		r = 0;
	if (g > 255)
		g = 255;
	else if (r < 0)
		g = 0;
	if (b > 255)
		b = 255;
	else if (b < 0)
		b = 0;

	str[0] = '#';
	str[7] = '\0';
	while(++i < 4) {
		int tmp;

        tmp = (i == 1 ? r : i == 2 ? g : b);
		str[2 * i - 1] = tmp / 16 < 10 ? '0' + tmp / 16: 'a' + tmp / 16 - 10;
		str[2 * i] = tmp % 16 < 10 ? '0' + tmp % 16 : 'a' + tmp % 16 - 10;
	}
	return (str);
}
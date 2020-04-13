#include <unistd.h>

/*
** Un octet ( 8bits ) donne 256 possibiliter soit une range de 0 - 255
** Un nombre hexadecimal a 16 possibiliter(0123456789abcdef), il faut 4 bits pour stocker ce nombre ( 2 ^ 4 )
** On retrouve donc dans un octet deux nombres en hexadecimal 0bXXXXAAAA
** 
** ft_rgb2hex utilise un buffer static de taille fixe non allouer pour contenir le format desirer et le retourner
** '#RRGGBB\0'
** Chaque "channel" r, g ou b contient deux lettres affichable, pour les convertires,
** on isole chaque partie a l'aide d'un & logique: 0 & 0 == 0, 1 & 0 == 0, 1 & 1 == 1
** le resultat est une valeur entre 0 - 15, la chaine constante `source` contient son equivalence en caractere affichable
** 0 == "0", 1 == "1" ... 15 == "f" 
** Et on decale le premier pour ramener sa valeur entre 0 - 15
** Ex: 0b1100,0101
** 0b1100,0101 & 0b1111,0000 -> 0b1100,0000 (192) -> 0b1100,0000 >> 4 -> 0b0000,1100 (12) -> source[12] -> "c"
** 0b1100,0101 & 0b0000,1111 -> 0b0000,0101 (5) -> source[5] -> "5"
** 0b11000101 (197) -> 0xc5
** Ce principe est utiliser pour chaque channel, pour effectuer la conversion et positionner correctement chaque valeur.
**
** L'utilisateur ne dois pas Free() la valeur de retour de cette fonction, il est responsable d'en faire une copie si besoin.
** Chaque appel ecrase la conversion precedente. 
** La fonction ignore toute valeur au dessus de 255 pour chaque channel effectuer:
** ft_rgb2hex(0b1100000000110000, 0, 0) et
** ft_rgb2hex(0b0000000000110000, 0, 0) donne un resultat est identique.
*/

char					*ft_rgb2hex(int r, int g, int b)
{
	static char			buffer[8];
	static const char	source[] = "0123456789abcdef";

	buffer[0] = '#';
	buffer[1] = source[(r & 0b11110000) >> 4];
	buffer[2] = source[r & 0b00001111];
	buffer[3] = source[(g & 0b11110000) >> 4];
	buffer[4] = source[g & 0b00001111];
	buffer[5] = source[(b & 0b11110000) >> 4];
	buffer[6] = source[b & 0b00001111];
	buffer[7] = 0;
	return (buffer);
}

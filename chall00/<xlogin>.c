#include <string.h>
#include <stdio.h>

/*Je verifie si les 2 chaine on la meme taille. je parcour ensuite les chaine 
a "l'infini" (l'index reviens a 0 des qu'il y a un \0) en incrementant
l'index de s1 de +1 par essai. si l'on a autant de caractere similaire
a la suite que la taille de s1 je return 1. si j'ai plus d'essai que 2*
la taille de s2 la bucle stop et je retourne 0*/

int ft_necklace(char *s1, char *s2)
{
    int i;
    int res;
    int y;
    int d;

    i = 0;
    res = 0;
    y = 0;
    d = 0;
    if (strlen(s1) != strlen(s2))
        return(0);
    if (s1[0] == '\0' && s2[0] == '\0')
        return(1);
    while (d < 2*(int)strlen(s2))
    {
        d++;
        if (s2[i] == '\0')
            i = 0;
        if (s1[y] == '\0')
            y = 0;
        if (s1[y] == s2[i])
        {
            y++;
            i++;
            res += 1;
        }
        else
        {
            y = 0 + d;
            i = 0;
            res = 0;
        }
        if (res == (int)strlen(s1))
            return(1);
        
    }
        return (0);
}
    #include <stdlib.h>
    #include <string.h>

    char *ft_rgb2hex(int r, int g, int b)
    {
        char *res;
        char *dicohex;

        dicohex = "0123456789abcdef";
        if (!(res = (char *)malloc(sizeof(char) * 8)))
            return NULL;
        res[0] = '#';
        res[1] = dicohex[r / 16];
        res[2] = dicohex[r % 16];
        res[3] = dicohex[g / 16];
        res[4] = dicohex[g % 16];
        res[5] = dicohex[b / 16];
        res[6] = dicohex[b % 16];
        res[7] = '\0';

        return (res);
    }
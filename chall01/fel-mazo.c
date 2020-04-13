#include <stdlib.h>

void    put_char_hex_buff(unsigned char val, char *buff, size_t offset)
{
    char            *charset = "0123456789abcdef";
    unsigned char   left;
    unsigned char   right;

    buff += offset;
    left = val >> 4;
    right = val & 0xf;
    *buff = charset[left];
    *(buff + 1) = charset[right];
}

char    *ft_rgb2hex(int r, int g, int b)
{
    char    *res;

    if (((r | g | b) & 0x100))
        return (NULL);
    if (!(res = (char *)malloc(sizeof(char) * 8)))
        return (NULL);
    res[0] = '#';
    put_char_hex_buff((unsigned char)r, res, 1);
    put_char_hex_buff((unsigned char)g, res, 3);
    put_char_hex_buff((unsigned char)b, res, 5);
    res[7] = 0;
    return (res);
}

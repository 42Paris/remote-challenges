#include <stdlib.h>


char* ft_rgb2hex(int r,int g,int b)
{
    char *hextalble;
    char* str;
    float result;
    int i;
    int v;

    if(r < 0 || r >255 || g < 0 || g > 255 || b < 0 ||b > 255) // basci check of rgb format
        return(NULL);
    hextalble = "0123456789abcdef";
    str = (char*)malloc(sizeof(char) * (7 + 1)); // size of hexa str and \0
    i = 1;
    str[0] = '#'; // add '#' att the first place
    str[7] = '\0'; // end of string

    while (i < 7) // forheach value (R,G,B) we need / 16 take int(result) hexa correspondance ,multiplie by 16 the floating part and take hexa correpodance
    {
        if(i == 1) // chose value (r,g,b)
            v = r;
        else if(i == 3)
            v = g;
        else 
            v = b;
        result = (float) v / 16;
        str[i] = hextalble[(int)result]; 
        // now we need to multyplie floating part of result by 16 and take corepodante value in hextalble
        str[i+1] = hextalble[(int) ((float)(result - (int)result) * 16)];
        i = i+2;
    }
    return(str);
}
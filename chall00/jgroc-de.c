#include <stdio.h>
#include <string.h>

int ft_checker(char *s1, char *s2, int i) {
    int j;

    j = 0;
    while (s2[j]) {
        if (s2[j] != s1[i]) {
            return 0;
        }
        ++j;
        ++i;
        if (!s1[i]) {
            i = 0;
        }
    }

    return 1;
}

int ft_necklace(char *s1, char *s2) {
    int i;

    if (strlen(s1) != strlen(s2)) {
        return 0;
    }
    if (strlen(s1) == 0) {
        return 1;
    }
    i = 0;
    while(s1[i]) {
        if (s2[0] == s1[i] && ft_checker(s1, s2, i)) {
            return 1;   
        }
        ++i;
    }

    return 0;
}
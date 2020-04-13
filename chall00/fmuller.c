/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmuller.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmuller <fmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 14:41:21 by fmuller           #+#    #+#             */
/*   Updated: 2020/04/06 14:41:22 by fmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int ft_necklace(char *s1, char *s2)
{
    char *match = strchr(s2, s1[0]);
    char *c;

    if (strlen(s1) != strlen(s2))
        return 0;

    while (match)
    {
        c = match;

        for (int i = 0; i < strlen(s1); i++)
        {
            if (*c != s1[i])
            {
                match = strchr(match + 1, s1[0]);
                if (!match)
                    return 0;
                continue;
            }

            c++;
            if (*c == '\0')
            {
                c = s2;
            }
        }
        return 1;
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    if (ft_necklace("nicole", "icolen") == 1) {
        printf("good\n");
    } else {
        printf("bad\n");
    }

    if (ft_necklace("nicole", "lenico") == 1) {
        printf("good\n");
    } else {
        printf("bad\n");
    }

    if (ft_necklace("nicole", "coneli") == 0) {
        printf("good\n");
    } else {
        printf("bad\n");
    }

    if (ft_necklace("aabaaaaabaab", "aabaabaabaaa") == 1) {
        printf("good\n");
    } else {
        printf("bad\n");
    }

    if (ft_necklace("abc", "cba") == 0) {
        printf("good\n");
    } else {
        printf("bad\n");
    }

    if (ft_necklace("xxyyy", "xxxyy") == 0) {
        printf("good\n");
    } else {
        printf("bad\n");
    }

    if (ft_necklace("xyxxz", "xxyxz") == 0) {
        printf("good\n");
    } else {
        printf("bad\n");
    }

    if (ft_necklace("x", "x") == 1) {
        printf("good\n");
    } else {
        printf("bad\n");
    }

    if (ft_necklace("x", "xx") == 0) {
        printf("good\n");
    } else {
        printf("bad\n");
    }

    if (ft_necklace("x", "") == 0) {
        printf("good\n");
    } else {
        printf("bad\n");
    }

    if (ft_necklace("", "") == 1) {
        printf("good\n");
    } else {
        printf("bad\n");
    }

    return 0;
}

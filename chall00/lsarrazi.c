/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsarrazi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsarrazi <lsarrazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/07 07:42:17 by lsarrazi          #+#    #+#             */
/*   Updated: 2020/04/07 07:57:33 by lsarrazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define _GNU_SOURCE
#include <string.h>

int ft_necklace(char *a, char *b)
{
    const size_t    blen = strlen(b);
    const size_t    alen = strlen(a);
    char            double_b[blen * 2];

    if (blen != alen)
        return (0);
    memcpy(double_b, b, blen);
    memcpy(double_b + blen, b, blen);
    return (memmem(double_b, blen * 2, a, alen) != 0);
}

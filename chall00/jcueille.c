/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jcueille.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcueille <jcueille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:00:04 by jcueille          #+#    #+#             */
/*   Updated: 2020/04/06 15:29:51 by jcueille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *s)
{
    int i;

    i = 0;
    if (!(*s))
        return (0);
    while (s[i])
        i++;
    return (i);
}

int ft_necklace(char *s1, char *s2)
{
    int len;
    int i;
    int j;

    i = 0;
    if (!(*s1) && !(*s2))
        return (1);
    if ((!(*s1) && *s2) || (*s1 && !(*s2)))
        return (0);
    while (s2[i] != *s1 && s2[i])
        i++;
    len = ft_strlen(s1);
    if (len != ft_strlen(s2))
        return (0);
    while (len > 0)
    {
        if (!(s2[i]) && len > 0)
            i = 0;
        if (*s1 != s2[i])
            return (0);
        s1++;
        i++;
        len--;
    }
    return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ede-banv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 15:43:42 by marvin            #+#    #+#             */
/*   Updated: 2020/04/06 15:43:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
    int i = 0;

    while (str && str[i])
        i++;
    return (i);
}

int ft_slide(char *s1, char *s2, int n)
{
    int start = n;
    while (s2[n])
    {
        if (*s1 == s2[n++])
            s1++;
        else
            return (0);
    }
    if (s2[n] == (int)'\0' && *s1 != (int)'\0')
    {
        n = 0;
        while (n < start)
        {
            if (*s1 == s2[n++])
                s1++;
            else
                return (0);
        }
        if (n == start)
            return (1);
    }
    return (1);
}

int ft_necklace(char *s1, char *s2)
{
    int cmp1 = 0;
    int cmp2 = 0;
    int i = 0;
    if (!s1 || !s2 || (ft_strlen(s1) != ft_strlen(s2)))
        return (0);
    if (s1[0] == '\0' && s2[0] == '\0')
        return (1);
    while (s1[i] && s2[i])
    {
        cmp1 += (int)s1[i];
        cmp2 += (int)s2[i];
        i++;
    }
    if (cmp1 != cmp2)
        return (0);
    i = 0;
    while (s1[i])
    {
        if (ft_slide(s1, s2, i))
            return (1);
        i++;
    }
    return (0);
}
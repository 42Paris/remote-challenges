/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   abezanni.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adrienbezannier <adrienbezannier@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/06 21:43:20 by adrienbezan       #+#    #+#             */
/*   Updated: 2020/04/06 22:27:26 by adrienbezan      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int ft_check_diff(char *s1, char *s2, int begin)
{
    int i;
    int j;

    i = 0;
    j = begin;
    while(s1[i])
    {
        if (!s2[j])
            j = 0;
        if (s1[i] != s2[j])
            return 0;
        i++;
        j++;
    }
    return (1);
}

int ft_necklace(char *s1, char *s2)
{
    int lens1;
    int lens2;
    int i;

    if (!s1 || !s2)
        return (0);
    lens1 = ft_strlen(s1);
    lens2 = ft_strlen(s2);
    if (lens1 != lens2)
        return (0);
    i = 0;
    while (s1[i])
    {
        if (ft_check_diff(s1, s2, i))
            return (1);
        i++;
    }
    return (lens1 == 0);
}

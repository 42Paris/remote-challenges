/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jmartel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmartel <jmartel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 20:55:52 by jmartel           #+#    #+#             */
/*   Updated: 2020/04/13 21:42:25 by jmartel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
** Take a number between 0 and 255, and convert it to hexadecimal format
** Result is written in the two firts bytes of result pointer.
*/
void	ft_itoa_hex(char *result, int number)
{
	char	*values = "0123456789abcdef";

	result[0] = values[number / 16];
	result[1] = values[number % 16];
}

/*
** Take red, green and blue ints as parameter and return their value
** encoded in hexadecimal color format.
** The resulting string is malloced with an 8 chars size.
** If any error happened, NULL pointer is returned.
** For example 252, 186, 3 returns "#fcba03".
*/
char	*ft_rgb2hex(r, g, b)
{
	char	*result;

	if (r > 255 || g > 255 | b > 255)
		return (NULL);
	if (r < 0 || g < 0 | b < 0)
		return (NULL);
	if (!(result = malloc(8)))
		return (NULL);
	result[0] = '#';
	ft_itoa_hex(result + 1, r);
	ft_itoa_hex(result + 3, g);
	ft_itoa_hex(result + 5, b);
	result[7] = '\0';
	return (result);
}

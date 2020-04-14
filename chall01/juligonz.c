/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   juligonz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juligonz <juligonz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 23:23:10 by juligonz          #+#    #+#             */
/*   Updated: 2020/04/13 23:50:37 by juligonz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define HEX_BASE "0123456789abcdef"

char	*ft_rgb2hex(int r, int g, int b)
{
	char *result;

	if (r < 0 || r > 255 ||
		g < 0 || g > 255 ||
		b < 0 || b > 255)
		return (NULL);
	if (!(result = malloc(8)))
		return (NULL);
	
	result[0] = '#';
	result[1] = HEX_BASE[r / 16];
	result[2] = HEX_BASE[r % 16];
	result[3] = HEX_BASE[g / 16];
	result[4] = HEX_BASE[g % 16];
	result[5] = HEX_BASE[b / 16];
	result[6] = HEX_BASE[b % 16];
	result[7] = '\0';
	return (result);
}

/*
void test(int r, int g, int b, char *expected)
{
	int		ret = 1;
	char	*result;

	result = ft_rgb2hex(r, g, b);
	if (result != NULL && expected != NULL)
		ret = strcmp(result, expected);
	else
	{
		printf("%s (%d) --->  (actual=\"%s\", expected=\"%s\")\n",
			   (result == NULL && expected == NULL ? "Ok" : "Bad"),
			   ret, result, expected);
		return ;
	}
	printf("%s (%d) --->  (actual=\"%s\", expected=\"%s\")\n",
		   (!ret ? "Ok" : "Bad"), ret, result, expected);
	free(result);
}

int main(void)
{
	//valid test
	test(252, 186,   3, "#fcba03");
	test(0  ,   0,   0, "#000000");
	test(255, 255, 255, "#ffffff");
	test(3, 177, 252, "#03b1fc");

	//null test
	test(255, 255, 256, NULL);
	test(255, 256, 255, NULL);
	test(256, 255, 255, NULL);
	test(255, 255, -1, NULL);
	test(255,  -1, 0, NULL);
	test(-1,  0, 0, NULL);

}
*/

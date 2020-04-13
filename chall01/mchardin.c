#include <stdlib.h>

void		ft_conv_base(int nbr, int lg_nb, char *base_to, char *new_base)
{
	if (lg_nb > 1)
		ft_conv_base(nbr / 16, lg_nb - 1, base_to, new_base);
	new_base[lg_nb - 1] = base_to[nbr % 16];
}

int			ft_RGB_to_int(int r, int g, int b)
{
	return(b + 256 * g + 65536 * r);
}

char 		*ft_rgb2hex(int r, int g, int b)
{
	char *res;

	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		return (NULL);
	if (!(res = malloc(sizeof(char) * 8)))
		return (NULL);
	res[0] = '#';
	ft_conv_base(ft_RGB_to_int(r, g, b), 6, "0123456789abcdef", &res[1]);
	res[7] = 0;
	return (res);
}

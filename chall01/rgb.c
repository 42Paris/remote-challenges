
#include <stdlib.h>

char	is_correct_color_value(int color) {
	return (color >= 0 && color <= 255);
}

void	color_to_hex(char *hex, int color, char *index) {
	char *hex_array = "0123456789abcdef";
	hex[*index] = hex_array[color % 16];
	hex[--(*index)] = hex_array[(color / 16) % 16];
	*index += 3;
}


char	*ft_rgb2hex(int r, int g, int b) {
	char *hex;
	char index = 2;

	if (!(is_correct_color_value(r) && is_correct_color_value(g) && is_correct_color_value(b)))
		return(NULL);
	if ((hex = (char*)malloc(8)) == NULL)
		return(NULL);
	hex[0] = '#';
	hex[7] = '\0';
	color_to_hex(hex, r, &index);
	color_to_hex(hex, g, &index);
	color_to_hex(hex, b, &index);
	return (hex);
}


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char *ft_rgb2hex( int r, int g, int b )
{
	char *s;

	if ( !( s = malloc( 8 ) ) )
		return NULL;

	sprintf( s, "#%02hhx%02hhx%02hhx", ( uint8_t ) r, ( uint8_t ) g, ( uint8_t ) b );
	return s;
}

/*void main( int ac, char **av )
{
	if ( ac < 4 )
		return;

	puts( ft_rgb2hex( atoi( av[1] ), atoi( av[2] ), atoi( av[3] ) ) );
}*/


// It's always better with horses. Always.

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int ft_necklace( char *s1, char *s2 )
{
	size_t len, count;
	char *cs2, *backup;

	// If lens don't match, bye bye
	if ( ( len = strlen( s1 ) ) != strlen( s2 ) )
		return 0;

	// Allocate 2x len buffer for string two copying, see why later
	if ( !( cs2 = malloc( len * 2 ) ) )
		return 0;
	strcpy( cs2, s2 );

	// Declare some shit
	backup = cs2;
	count = len - 1;

	do
	{
		// If string one match string two copy, we have a necklace :3
		if ( !strcmp( s1, cs2 ) )
		{
			free( backup );
			return 1;
		}

		// Fast rotate string two copy ( reason for the double sized buffer )
		cs2[len] = *cs2;
		cs2[len + 1] = 0;
		cs2++;
	}
	while ( count-- );

	// Complete rotation was done, and no match has occured.
	// We don't have a necklace :(
	free( backup );
	return 0;
}

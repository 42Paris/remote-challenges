
// And remember, everything is better with horses. Everything.

#include <string.h>
#include <stdlib.h>

int ft_necklace( char *s1, char *s2 )
{
	size_t len, count;
	char *cs2, *backup;

	// If lens don't match, bye bye
	if ( ( len = strlen( s1 ) ) != strlen( s2 ) )
		return 0;

	// If len is zero, we can directly say we have a necklace ( a very shitty one tho )
	if ( !len )
		return 1;

	// Allocate 2x len buffer for string two copying, see why later
	if ( !( cs2 = malloc( len * 2 ) ) )
		return 0;
	strcpy( cs2, s2 );

	// Declare some shit
	backup = cs2;
	count = len - 1;

	// If string one match string two copy, we have a necklace :3
top:	if ( !strcmp( s1, cs2 ) ) // Uh-Oh, a label ... does that mean .. no, it can't be ...
	{
		free( backup );
		return 1;
	}

	// If count reached zero, complete rotation was done, and no match has occured.
	// We don't have a necklace :(
	if ( !count-- )
	{
		free( backup );
		return 0;
	}

	// Fast rotate string two copy ( reason for the double sized buffer )
	cs2[len] = *cs2;
	cs2[len + 1] = 0;
	cs2++;
	goto top; // Aaaaah ! I knew it, a GOTO statement ! Run for your lives !
}

// Joke aside, i used goto to make a custom loop, 'elegantly' marrying speed and concision :3

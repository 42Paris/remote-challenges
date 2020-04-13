#include <strings.h>

/**
 * Assuming both strings are of the same length 'len'
 * and knowing s2 won't begin at its first character
 * we compare each character until 's1' end.
 * On reaching 's2' end, we just have to go back to the beginning
 * by substracting 'len' to the pointer, as 'len' is supposed
 * to be the length of both strings.
**/
static int	rotate_compare(char *s1, char *s2, size_t len) {
	while (*s1 && *s1 == *s2) {
		s1++;
		if (!*(++s2))
			s2 -= len;
	}
	return (*s1);
}

/**
 * If both strings are not of the same length
 * they can't be the same necklace.
 * If both strings are of the same length we will
 * iterate on each character of 's2' corresponding
 * to the first character of 's1' using 'strchr'.
 * In the process, using 'rotate_compare' we will compare
 * both strings at different starting points of 
 * 's2'. If they never match the necklaces are differents.
**/
int			ft_necklace(char *s1, char *s2) {
	size_t len;

	len = strlen(s1);
	if (len != strlen(s2))
		return (0);
	while (s2) {
		if (!rotate_compare(s1, s2, len))
			return (1);
		s2 = strchr(s2 + 1, *s1);
	}
	return (0);
}

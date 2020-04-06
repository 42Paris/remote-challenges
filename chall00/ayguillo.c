#include <strings.h>
#include <string.h>
#include <stdlib.h>


char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	size;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	size = strlen(s1) + strlen(s2) + 1;
  if (!(s3 = malloc(size)))
    return(NULL);
	i = 0;
	while (*s1)
		s3[i++] = *(s1++);
	while (*s2)
		s3[i++] = *(s2++);
	s3[i] = 0;
	return (s3);
}

int ft_necklace(char *s1, char *s2)
{
  int i_s1 = 0;
  int i_s2 = 0;
  char *s_compare = ft_strjoin(s1, s1);
  int i_compare;
  int match;

  if (strlen(s1) == 0 && strlen(s2) == 0)
    return(1);
  if (strlen(s1) != strlen(s2))
    return(0);
  while (s_compare[i_s1++])
  {
    i_s2 = 0;
    if (s2[i_s2] == s_compare[i_s1])
    {
      i_compare = i_s1;
      match = 0;
      while (s2[i_s2] && s_compare[i_compare] && s2[i_s2] == s_compare[i_compare])
      {
        i_s2++;
        i_compare++;
        match++;
        if (s2[i_s2] == '\0' && match==strlen(s2))
          return(1);
      }
    }
  }
  return(0);
}

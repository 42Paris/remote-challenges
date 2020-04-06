#include <string.h>
#include <stdlib.h>

void rotate(char **str, int len)
{
  int i = 0;
  char tmp = str[0][len - 1];
  char tmp2;

  while (i < len)
  {
    tmp2 = str[0][i];
    str[0][i] = tmp;
    tmp = tmp2;
    i++;
  }
}

int ft_necklace(char *str1, char *str2)
{
  char *cp;
  int len = strlen(str2);
  int i = 0;

  if(len == 0 && strlen(str1) == 0)
    return 1;
  if (len != strlen(str1))
    return 0;
  cp = (char *)malloc(len * sizeof(char));
  strcpy(cp, str2);
  while (i < len)
  {
    if (!strcmp(cp, str1))
      return (1);
    rotate(&cp, len);
    i++;
  }
  return (0);
}
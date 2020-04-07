#include <stdlib.h>

int	ft_strlen(const char *str)
{
  int	len;

  len = 0;
  while (*str)
    {
      ++str;
      ++len;
    }
  return (len);
}

char	*ft_strdup(const char *str)
{
  int	len;
  char	*dup;

  len = ft_strlen(str);
  dup = (char *)malloc(sizeof(char) * (len + 1));
  if (dup == NULL)
    {
      return (NULL);
    }
  while (*str != 0)
    {
      *dup = *str;
      ++str;
      ++dup;
    }
  *dup = 0;
  return (dup - sizeof(char) * len);
}

int ft_strcmp(char *s1, char *s2)
{
  while (*s1 && *s2)
    {
      if (*s1 == *s2)
	{
	  ++s1;
	  ++s2;
	}
      else
	{
	  return (*s1 - *s2);
	}
    }
  return (*s1 - *s2);
}

void ft_strshift(char *str)
{
  char	buf;

  buf = *str;
  while (*str)
    {
      *str = *(str + sizeof(char));
      ++str;
    }
  *(str - sizeof(char)) = buf;
}

int ft_necklace(char *s1, char *s2)
{
  int	len;
  char	*dup;

  if (ft_strcmp(s1, s2) == 0)
    {
      return (1);
    }
  dup = ft_strdup(s1);
  len = ft_strlen(s1);
  while(*dup && *s2 && len)
    {
      if (ft_strcmp(dup, s2) == 0)
	{
	  return (1);
	}
      else
	{
	  ft_strshift(dup);
	  --len;
	}
    }
  return (0);
}

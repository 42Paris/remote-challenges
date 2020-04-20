
char *ft_rgb2hex(int r, int g, int b)
{
  char *ret;
  char *val ="0123456789abcdef";
  int current;
  if ((r < 0) || (r > 255) || (g < 0) || (g > 255) ||  (b < 0) || (b > 255))
    return (NULL);
  if (!(ret = (char *)malloc(sizeof(char) * 7)))
    return (NULL);
  ret[0] = '#';
  int i = 1;
  while (i < 7)
  {
    if (i < 3)
        current = r;
    else if (i >= 3 && i < 5)
        current = g;
    else if (i >= 5)
        current = b;

      ret[i] = val[(current / 16)];
      i++;
      ret[i] = val[(current % 16)];
      i++;
  }
  return (ret);
}

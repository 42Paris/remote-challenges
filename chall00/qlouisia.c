int ft_strlen(char *str)
{
  int i = 0;
  
  while (str[i])
  i++;
  return(i);
}

int ft_necklace(char *s1, char *s2)
{
  int len = ft_strlen(s1);
  if (len != ft_strlen(s2))
    return (0);
  else if (len == 0)
    return(1);
  int it = 0;
  int curs= 0;
  int ref = 0;
  int prev_curs = 0;
  while (prev_curs < len)
  {
    ref = 0;
    curs = prev_curs;
    while (s1[curs] != *s2 && (curs < len))
      curs++;
    if (curs > len)
      return (0);
    prev_curs = curs;
    while (s1[curs] == s2[ref] && it <= len)
    {
      curs++;
      it++;
      ref++;
      if (curs == len)
      {
        curs = 0;
      }
    }
    if (it == len)
      return (1);
    it = 0;
    prev_curs++;
  }
  return (0);
}

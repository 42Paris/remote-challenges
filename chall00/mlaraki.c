#include <stdlib.h>

// Step 1 : On vérifie que les 2 strings sont de tailles égales pour éviter tout calculs superflus
// Step 2 : On concatene la deuxième string 2 fois dans une variable temporaire pour être sûr de retrouver la première string dans le bon ordre dans cette variable temporaire;
// on utilise strnstr qui sert à retrouver la substring s1 dans notre variable temporaire 
// Step 3: strnstr renvoie NULL si s1 n'est pas présente dans notre variiable temporaire : On renvoi 0 dans ce cas et 1 sinon

// ---------- libft ----------
size_t	ft_strlen(const char *s)
{
	size_t size;

	size = 0;
	while (*s++ != '\0')
		size++;
	return (size);
}

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	unsigned int i;

	i = 0;
	if (!dst)
		return (0);
	if ((unsigned int)dstsize > 1)
	{
		while (src[i] != '\0' && i < ((unsigned int)dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	unsigned int	i;
	size_t			dstlen;
	size_t			srclen;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize <= dstlen)
		return (srclen + dstsize);
	while (*src != '\0' && i < (dstsize - dstlen - 1))
		*(dst + dstlen + i++) = *src++;
	*(dst + dstlen + i) = '\0';
	return (dstlen + srclen);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- > 0)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		else if (*s1 == '\0')
			return (0);
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int count;
	int count2;

	count = 0;
	count2 = 0;
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[count] != '\0' && count < (int)len)
	{
		while (haystack[count + count2] == needle[count2] &&
			haystack[count + count2] != '\0' && (count + count2) < (int)len)
			count2++;
		if (needle[count2] == '\0')
			return ((char*)(haystack + count));
		count++;
		count2 = 0;
	}
	return (NULL);
}

// ---------- ----------  ----------

int ft_necklace(char *s1, char *s2)
{
    char *tmp;
    size_t len_s1;
    size_t len_s2;

    len_s1 = ft_strlen(s1);
    len_s2 = ft_strlen(s2);
    if (len_s1 != len_s2) return (0);
    if(!(tmp = malloc((2*len_s2) * sizeof(char) + 1)))
        return (0);

    ft_strlcpy(tmp, s2, len_s1 + len_s2 + 1);
    ft_strlcat(tmp, s2, len_s1 + len_s2 + 1);

    free(tmp);
    return ft_strnstr(tmp, s1, ft_strlen(tmp)) == (NULL) ? 0 : 1;
}
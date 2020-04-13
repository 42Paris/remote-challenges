/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julnolle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julnolle <julnolle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 14:54:31 by julnolle          #+#    #+#             */
/*   Updated: 2020/04/13 15:36:02 by julnolle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	len;

	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest != NULL)
		ft_memcpy(dest, src, len + 1);
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	int		size;
	int		i;
	int		j;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	if (!(dst = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		dst[i + j] = s2[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}

void	ft_strjoin_front(const char *front, char **src)
{
	char *tmp;

	if (front == NULL || *src == NULL)
		return ;
	tmp = ft_strdup(*src);
	free(*src);
	*src = ft_strjoin(front, tmp);
	free(tmp);
}

int		rgb_to_int(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

size_t	ft_nbrsize_base(long n, size_t base_len)
{
	size_t len;

	if (n == 0)
		len = 1;
	else
	{
		len = (n < 0) ? 1 : 0;
		n = (n < 0) ? -n : n;
		while (n > 0)
		{
			n = n / base_len;
			len++;
		}
	}
	return (len);
}

char	*ft_itoa_base(long nb, char *base)
{
	char			*str;
	size_t			len;
	size_t			base_len;

	base_len = 16;
	len = ft_nbrsize_base(nb, base_len);
	str = NULL;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str)
	{
		str[len] = '\0';
		len--;
		if (nb == 0)
			str[len] = '0';
		while (nb > 0)
		{
			str[len] = base[nb % base_len];
			nb = nb / base_len;
			len--;
		}
	}
	return (str);
}

char	*ft_rgb2hex(int r, int g, int b)
{
	int		color;
	char	*str;

	str = NULL;
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (NULL);
	color = rgb_to_int(r, g, b);
	str = ft_itoa_base(color, "0123456789abcdef");
	ft_strjoin_front("#", &str);
	return (str);
}

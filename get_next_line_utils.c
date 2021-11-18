#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c && *s)
		s++;
	if (*s == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}
/*
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;

	if (!s1 || !s2)
		return (0);
	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s)
		return (0);
	ft_strlcpy(s, s1, (ft_strlen(s1) + ft_strlen(s2) + 1));
	ft_strlcat(&s[ft_strlen(s1)], s2, (ft_strlen(s1) + ft_strlen(s2) + 1));
	return (s);
}*/

size_t	ft_strlen(const char	*s)
{
	int	n;

	n = 0;
	while (*s)
	{
		n++;
		s++;
	}
	return (n);
}

char	*ft_strdup(const char *s1)
{
	char	*s;
	size_t	i;

	s = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (i <= ft_strlen(s1))
	{
		s[i] = s1[i];
		i++;
	}
	return (s);
}


size_t	ft_strlcat(char	*dst, const char *src, size_t dstsize)
{
	char		*d;
	const char	*s;
	size_t		n;
	size_t		dl;

	n = dstsize;
	s = src;
	d = dst;
	while (n-- != 0 && *d != '\0')
		d++;
	dl = d - dst;
	n = dstsize - dl;
	if (n == 0)
		return (dl + ft_strlen (s));
	while (*s != '\0')
	{
		if (n != 1)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = '\0';
	return (dl + (s - src));
}
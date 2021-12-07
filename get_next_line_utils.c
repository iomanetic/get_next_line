#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char				*str;
	unsigned int		i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char *) malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (str == NULL)
		return (NULL);
	while (*s1 != '\0')
		str[i++] = *s1++;
	while (*s2 != '\0')
		str[i++] = *s2++;
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s)
{
	char	*s_2;
	size_t  len_s;
	size_t	i;

	len_s = ft_strlen(s);
	i = 0;
	s_2 = (void *) malloc(sizeof(void) * len_s + 1);
	if (s_2 == NULL)
		return (NULL);
	while (i <= len_s)
	{
		s_2[i] = s[i];
		i++;
	}
    s_2[i] = '\0';
	return (s_2);
}

char	*ft_strchr(const char *s, int c)
{
	char	*temp;

	temp = (char *)s;
	while (*temp)
	{
		if (*temp == (char)c)
			return (temp);
		temp++;
	}
	if (*temp == (char)c)
		return (temp);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

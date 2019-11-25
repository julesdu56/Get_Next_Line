/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumourot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 12:36:20 by jumourot          #+#    #+#             */
/*   Updated: 2019/11/25 12:18:24 by jumourot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int i;

	i = 0;
	while (src[i] && dest[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	if (!(dest = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1))))
		return (NULL);
	while (s1[i])
	{
 		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*s2;

	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (!(s2 = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (s2 == NULL)
		return (NULL);
	i = 0;
	s2[len] = '\0';
	while (len)
	{
		len--;
		s2[i] = s[start + i];
		i++;
	}
	return (s2);
}

char				*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	while (str[i])
		i++;
	if ((char)c == '\0')
		return ((char *)&str[i]);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

static char		*ft_concat_all(char *dest, char const *s1, char const *s2)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	if (!dest)
		return (NULL);
	while (s1[j])
	{
		dest[j] = s1[j];
		j++;
	}
	while (s2[i])
	{
		dest[j] = s2[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	len;

	dest = NULL;
	if (!s1 && !s2)
		return (dest);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	if (!(dest = malloc(sizeof(char) * len)))
		return (NULL);
	ft_concat_all(dest, s1, s2);
	return (dest);
}

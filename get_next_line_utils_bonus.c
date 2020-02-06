/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumourot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 14:00:13 by jumourot          #+#    #+#             */
/*   Updated: 2020/02/05 14:01:35 by jumourot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t				ft_strlen(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char				*ft_strdup(const char *s1)
{
	int				i;
	char			*dest;

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

char				*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	char			*s2;

	if (s == NULL || len <= 0)
		return (NULL);
	if (!(s2 = (char*)malloc(sizeof(char) * (len + 1))))
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

char				*ft_strjoin(const char *s1, char const *s2)
{
	char			*tmp;
	size_t			size;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = (ft_strlen(s1) + ft_strlen(s2));
	if (!(tmp = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	*tmp = '\0';
	return (tmp - size);
}

void				ft_endof(int fd, char **str, char **line)
{
	if (*line == NULL)
		*line = ft_strdup(str[fd]);
	free(str[fd]);
	str[fd] = NULL;
}
